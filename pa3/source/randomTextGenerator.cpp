// SUBMIT THIS FILE

#include "randomTextGenerator.h"
#include <fstream>
using namespace std;

//read the file content from the file specified by the fileName, and save it to the data member original
//for Eclipse, the file should be put in the same location as the source files
//for other IDEs, you need to look it up yourself
//for simplicity, as the original text shouldn't contain any newline character,
//just read the first line in the file
//(i.e. read until the first newline character or EOF, but don't include those characters in the original)
void RandomTextGenerator::readOriginalFromFile(const char fileName[]){
	ifstream fileread(fileName);
	string line;
	while (getline(fileread, line))
		original += line;

}

//verify the original content text
//A valid text is defined as a text that consists of only valid characters
//return the null character '\0' if no invalid character is found
//otherwise, return the first invalid character found
//valid characters are
//- alphabets, lower case or upper case
//- digits (i.e., '0' - '9')
//- space ' '
//- comma ','
//- the following 8 symbols '.', ';', ':', '\'', '\"', '-', '!', '?'
//note that there should be no newline character ('\n') or other special characters (such as '\t' or '\r' or some chinese full-width character, etc.)
char RandomTextGenerator::verifyOriginal(){
	int length = original.length();
	for (int i = 0; i < length; i++){
		if ((original[i] >=32  && original[i] <= 34) || (original[i] >= 44  && original[i] <= 46) ||
			(original[i] >=48  && original[i] <= 59) || (original[i] >= 65  && original[i] <= 90) ||
			(original[i] >=97  && original[i] <= 122) || original[i] == 39  || original[i] == 63){
		}
		else return original[i];
	}
	return '\0';
}

//prepare the WFM
//check the webpage for explanation and examples
void RandomTextGenerator::prepareWFM(){
	Dictionary<string, Dictionary<string,int>> *init = new Dictionary<string, Dictionary<string,int>>;
	wfm = *init;
	delete init;
	int num_words = 0;
	int length = original.length();
	for (int i = 0; i < length; i++){
		if (original[i] == 32 && (original[i+1] != ' ' || original[i+1] != '\n' || original[i+1] != '\0')){
			num_words++;
		}
	}
	num_words = num_words +2;
	string words[num_words];
	int counter = 1;
	for (int j = 0; j < length; j++){
		if (original[j] == 32 && (original[j+1] != ' ' || original[j+1] != '\n' || original[j+1] != '\0')){
			counter++;
			continue;
		}
		else if (original[j] == ' ' || original[j] == '\0'){
			continue;
		}
		else{
		words[counter].push_back(original[j]);
		}
	}
	int newnumword= num_words;
	for (int i = 1 ; i < num_words; i++){
		if(words[i] == "")
			newnumword--;
	}
	string words2[newnumword];
	int counter2 = 1;
	for (int i = 1 ; i < num_words; i++){
		if(words[i] != ""){
			words2[counter2] = words[i];
			counter2++;
		}
		else continue;
	}
		for (int k = 0 ; k < newnumword - 1 ;k++){
			wfm[words2[k]][words2[k+1]]++;
		}
}

//generate a random text of the given length
//rng is used as the random number generator
//check the webpage for explanation and examples
string RandomTextGenerator::generate(RNG* rng, int length){
	if (wfm.getSize()== 0)
		return "";
	int keynum = 0;
	string os = "";
	string* words = wfm.getKeyList();
	string word = words[keynum];
	WeightedRandomItemPicker<string> picker;

	for (int i = 0; i < length ; i++){
		keynum = 0;
		for (int j = 0; j < wfm.getSize(); j++){
			if (words[j] == word){
				keynum = j;
				break;
			}
			else continue;
		}
		cout<< "Previous word is \""<<(keynum!=0?word:"")<<"\"."<<endl;
		Dictionary<string,int> *vlist = wfm.getValueList();
		Dictionary<string,int> key = vlist[keynum];
		int* weights = key.getValueList();
		string* words = key.getKeyList();
		word = picker.pick(weights, words, key.getSize(), rng);
		os += word;
		os += " ";
		delete[] vlist;
		delete[] weights;
		delete[] words;
	}
	delete [] words;
	return os;
}

