/***********************************************************************
* Program:
*    Assignment 32, Strings          (e.g. Assignment 10, Hello World)
*    Brother Foushee, CS124
* Author:
*    Caleb Nwokocha
* Summary:
*    This program counts how many letters of a specific kind is in a 
*    string of text.
*
*    Estimated:  1.0 hrs
*    Actual:     0.30 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <string>

using namespace std;

/*********************************************************************
* This function uses FOR loops to count the number a letters of a 
* specific kind in a string of text.
*********************************************************************/
int countLetters(char text[], char letter)
{
	int number = 0;

	for (int i = 256; i >= 0; i--)
	{
		if (text[i] == letter)
			number += 1;
	}

	return number;
}

/*********************************************************************
* This function calls the countLetters function and displays output on
* the screen.
*********************************************************************/
int main()
{
	char letter;
	char text[256];
	cout << "Enter a letter: ";
	cin >> letter;
	cout << "Enter text: ";
	cin.ignore();
	cin.getline(text, 256);

	for (int i = 256; i >= 0; i--)
	{
		if (text[i] == ' ')
		{
			text[i] = '_';
		}
	}

	cout << "Number of " << "'" << letter << "'s: " << countLetters(text, letter) << endl;
	return 0;
}