#include "utils.h"

Utils::Utils()  {}

Utils::~Utils()
{
    tree.release();
}

bool Utils::loadDictionary(const string& text_dic)
{
    // load the file with name text_dic, and save all characters in this->content
    ifstream load_file(text_dic);
    if (!load_file.is_open()) {
        cout << "Failed to load the article. Exit." << endl;
        return false;
    }

    ostringstream buf;
    char ch;
    while (buf && load_file.get(ch))
        buf.put(ch);
    this->content = buf.str();
    // move out the end useless '\r' of a file
    this->content.pop_back();

    load_file.close();

    // scan the string this->content, calculate the frequency table
    // insert your code here ...
    for (string::size_type i = 0; i < content.size(); i++){
    	frequency_table[content[i]]++;
    }

    return true;
}

void Utils::buildTree()
{
    tree.loadMap(frequency_table);
}

void Utils::setEncodedTable()
{
    tree.encode(encoded_table);
}

void Utils::saveBinDictionary(const string& bin_file)
{
    // load key file
    ifstream ifile("xor_key.bin", ios::binary);
    if (!ifile.is_open()) {
        cout << "cannot load key file, exit." << endl;
        return;
    }

    ofstream ofile(bin_file, ios::binary);

    // assuming that the length of bin_code is multiple of 8
    // so just for every 8 continuous {0,1} characters, intepret it as a binary byte number
    // for last byte you write, its valid length may be less than 8, fill the invalid bits with 0
    // eg., last byte contains only 3 valid bits, 110. You should fill it as 1100 0000, and then
    // you need to write integer 3 (bin form: 0000 0011) as one byte at the beginning of your binary file.
    // after saving data into .bin file, you should print out its hex form in command line
    // insert your code here ...

    string encode = "";
    for (unsigned i = 0; i < content.size(); i++){
    	if (content [i] != '\0')
    	encode = encode + encoded_table.find(content[i])->second;
    }
    int length = encode.size();
    int checkbit = 8 - (length % 8);
    for (int i = 0; i < checkbit; i++)
    	encode += "0";
    string fullencode;
    switch(length%8)
    {
    	case 1:
    		fullencode += "00000001";
    		break;
    	case 2:
    		fullencode += "00000010";
    		break;
    	case 3:
    		fullencode += "00000011";
    		break;
    	case 4:
    		fullencode += "00000100";
    		break;
    	case 5:
    		fullencode += "00000101";
    		break;
    	case 6:
    		fullencode += "00000110";
    		break;
    	case 7:
    		fullencode += "00000111";
    		break;
    	default:
    		fullencode += "00000000";
    		break;
    }

    fullencode += encode;

    int bytelength = static_cast<int>(fullencode.size())/8;
    unsigned char code[bytelength] ;
    unsigned char decimal = 0b00000000;

    for(string::size_type i = 0; i < fullencode.size(); i++){
    	if (fullencode[i] == '1'){
    		switch(i%8){
    			case 0 :
    				decimal = decimal | 128;
    				break;
    			case 1 :
    				decimal = decimal | 64;
    				break;
    			case 2 :
    				decimal = decimal | 32;
    				break;
    			case 3 :
    				decimal = decimal | 16;
    				break;
    			case 4 :
    				decimal = decimal | 8;
    				break;
    			case 5 :
    				decimal = decimal | 4;
    				break;
    			case 6 :
    				decimal = decimal | 2;
    				break;
    			case 7 :
    				decimal = decimal | 1;
    				break;
    		}
    	}
		if (i%8 == 7){
			code[i/8] = 0b00000000 | decimal;
			decimal = 0b00000000;
		}
    }

	char ch;
	int k = 0;
    while(ifile.get(ch)){
    	ofile << (unsigned char)(ch ^ code[k]);
    	cout<< setw(2) << setfill('0')<< hex<<((unsigned char)ch ^ code[k]);
    	k++;
    	if(k >= bytelength){
    		cout<<endl;
    		break;
    	}
    }
    cout<< endl;

    ifile.close();
    ofile.close();

}

void Utils::decode(const string& bin_file)
{
    ifstream ifile(bin_file, ios::binary);
    if (!ifile.is_open()) {
        cout << "cannot open .bin file, stop decoding." << endl;
        return;
    }

    ifstream key_file("xor_key.bin", ios::binary);
    if (!key_file.is_open()) {
        cout << "cannot load key file, exit." << endl;
        return;
    }
    
    // the string used to search on huffman tree to decode as plaintext
    string bit_str = "";

    // bin_file: stores a binary huffman code with possible extra bits at the end
    // key_file: decryption XOR key
    // search in the encoded table
    // insert your code here ...

    stringstream s;
    char ch1,ch2;

    while(key_file.get(ch2)&& ifile.get(ch1)){
    		s<<setw(2) << setfill('0')<< hex<<((unsigned char)ch1 ^(unsigned char)ch2);
    	}

   string hex_str = s.str();
    int i = 2;

    while (hex_str[i]){
    	switch(hex_str[i]){
    	case '0':
			bit_str += "0000";
			break;
		case '1':
			bit_str += "0001";
			break;
		case '2':
			bit_str += "0010";
			break;
		case '3':
			bit_str += "0011";
			break;
		case '4':
			bit_str += "0100";
			break;
		case '5':
			bit_str += "0101";
			break;
		case '6':
			bit_str += "0110";
			break;
		case '7':
			bit_str += "0111";
			break;
		case '8':
			bit_str += "1000";
			break;
		case '9':
			bit_str += "1001";
			break;
		case 'a':
			bit_str += "1010";
			break;
		case 'b':
			bit_str += "1011";
			break;
		case 'c':
			bit_str += "1100";
			break;
		case 'd':
			bit_str += "1101";
			break;
		case 'e':
			bit_str += "1110";
			break;
		case 'f':
			bit_str += "1111";
			break;
    	}
    	i++;
    }

    int checkbit = hex_str[1] - '0';
    for (int j = 0; j <(8-checkbit); j++)
    	bit_str.pop_back();

    ifile.close();
    key_file.close();

    // using huffman tree you've built before to decode the bit string
    string plaintext = tree.decode(bit_str);
    cout << plaintext << endl << endl;
}
