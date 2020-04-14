/*
 * pa1.cpp
 *
 *  Created on: 2018. 10. 12.
 *      Author: kijun
 */

#include <iostream>
#include <cstring>

using namespace std;

const char NULL_CHAR = '\0';

/*
 * Function: digits_to_barcode
 * To convert the given digit string to a barcode string
 * Return nothing (void)
 */
void barcode_creat(int x, int i, const char barcodes[][6], char output_barcode[])
{
    for (int j=0;j<6;j++)
    {
        int k = (i*5)+j;
        output_barcode[k] = barcodes[x][j];

    }
}
//***

//****
void digits_to_barcode(const char barcodes[][6], char input_string[], char output_barcode[])
{
	int z = 0;
	int x = 0;
	int y = 4500;
    for (int i=0;i<500;i++)
    {
    	z = i;
    	if (input_string[i] == NULL_CHAR)
    	{break;}
        x = input_string[i] - '0';
        y = y- x;

            switch (x)
            {

            case 0:
            barcode_creat(x,i,barcodes,output_barcode);
            break;

            case 1:
            barcode_creat(x,i,barcodes,output_barcode);
            break;

            case 2:
            barcode_creat(x,i,barcodes,output_barcode);
            break;

            case 3:
            barcode_creat(x,i,barcodes,output_barcode);
            break;

            case 4:
            barcode_creat(x,i,barcodes,output_barcode);
            break;

            case 5:
            barcode_creat(x,i,barcodes,output_barcode);
            break;

            case 6:
            barcode_creat(x,i,barcodes,output_barcode);
            break;

            case 7:
            barcode_creat(x,i,barcodes,output_barcode);
            break;

            case 8:
            barcode_creat(x,i,barcodes,output_barcode);
            break;

            case 9:
            barcode_creat(x,i,barcodes,output_barcode);
            break;

            default:
            break;

            }
    }
    	x = y % 10;
    	barcode_creat(x,z,barcodes,output_barcode);
}

/*
 * Function: barcode_to_digits
 * Return true and store the digits in digit_string if barcode is valid;
 * Return false otherwise
 */

//*****
bool barcode_check(char input_string[])
{
bool valid = true;
	for (int i = 0; i < 501; i++)
	{
		if (input_string[i] == NULL_CHAR){
			break;
		}
		else if (input_string[i] == 124 || input_string[i] == 39){
			valid = true;
		}
		else if (input_string[i] != 124 || input_string[i] != 39){
			return false;
		}
	}
	return valid;
}
//****
bool digit_creat(const char barcodes[] [6],char temp_bar[],char digit_string[], int x)
{
	for (int h=0; h<10; h++){

	int b = 0;

		for (int i = 0; i < 6; i++){
			if (temp_bar[i] != barcodes[h][i]){
				break;
			}
			else if (temp_bar[i] == barcodes[h][i])	{
				b = b + 1;
				continue;
			}
		}

		 if (b != 6)
		{
			continue;
		}
		else if ( b == 6 )
		{
			digit_string[x] = h + '0';
			return true;
		}
	}
	return false;
}



//****
bool conversion(const char barcodes[] [6],char input_string[], char digit_string[])
{
	int a = 0;
	char temp_bar[6] = "";
	for (int i = 0; i < 501; i++)
	{

		for (int j = 0; j < 6; j++)
		{
			a = (i*5)+j;
			temp_bar[j] = input_string[a];

		}

		if(digit_creat(barcodes,temp_bar,digit_string,i))
		{
			return true;
		}
		else
			return false;
	}
return true;
}
//****
bool barcode_to_digits(const char barcodes[] [6], char input_string[], char digit_string[])
{
    bool bar= true;
	int x = 0;

	for (int i = 0; i<501; i++){
		if(input_string[i] == NULL_CHAR)
		{
			break;
		}
		if(!barcode_check(input_string)||!conversion(barcodes, input_string, digit_string)){
			goto wrong;
		}
		else if (barcode_check(input_string) && conversion(barcodes, input_string, digit_string)){
			bar = true;
		}

		x = x + 1;
	}


	if (x % 5 == 0)
	{
		bar = true;
	}
	else if (x % 5 !=0)
	{
		wrong:
		bar = false;
	}
	return bar;
}



/*
 * Function: main
 * You are NOT ALLOWED to change ANY CODE in this function
 */
int main()
{
	const char barcodes[][6]=
		{
			"'''||",
			"||'''",
			"|'|''",
			"|''|'",
			"|'''|",
			"'||''",
			"'|'|'",
			"'|''|",
			"''||'",
			"''|'|"
		};

	int option;
	char input_string[501];		// a barcode or digit string

	do {
		cout << endl;
		cout << "Welcome to the barcode program!" << endl;
		cout << "Please select an option to proceed:" << endl;
		cout << "1. Convert digits to barcode" << endl;
		cout << "2. Revert digits from barcode" << endl;
		cout << "3. Exit" << endl << endl;

		cout << "Your option: ";
		cin >> option;

		switch(option)
		{
			case 1:
				cout << "Please enter the digit sequence: ";
				cin >> input_string;

				char output_barcode[2506];		// barcode string
				digits_to_barcode(barcodes, input_string, output_barcode);
				cout << "The barcode is: " << output_barcode << endl;
				break;

			case 2:
				cout << "Please enter the barcode: ";
				cin >> input_string;

				char digit_string[101];
				if (barcode_to_digits(barcodes, input_string, digit_string))
					cout << "The digit sequence is: " << digit_string << endl;
				else
					cout << "Invalid barcode." << endl;
				break;

			case 3:
				break;

			default:
				cout << "Invaid option. Please try again." << endl;
				break;
		}

	} while (option != 3);

	return 0;
}






