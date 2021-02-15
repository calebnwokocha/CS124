/***********************************************************************
* Program:
*    project 12, Sudoku (e.g. Assignment 10, Hello World)
*    Brother Foushee, CS124
* Author:
*    Caleb Nwokocha
* Summary:
*    This Sudoku game program that prompts the user of various inputs, 
*    displays the game board on screen, and saves the game data to a 
*    specified file.
*
*    Estimated:  0.0 hrs
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void getFileName(string &fileName);
void readBoard(string fileName, string boardCharacters[]);
char getInput(string& secondInput);
string editBoard(string boardCharacters[], string input);
void writeBoard(string boardCharacters[], string fileName);
void displayBoard(string boardCharacters[]);


/*********************************************************************
* MAIN
* Starts the program and calls other functions.
*********************************************************************/
int main()
{
	string fileName;
	getFileName(fileName);

	string boardCharacters[256];
	readBoard(fileName, boardCharacters);

	string instructions = "Options:\n   ?  Show these instructions\n   D  Display the board\n   E  Edit one square\n   S  Show the possible values for a square\n   Q  Save and Quit\n";
	cout << instructions;

	cout << "\n";
	displayBoard(boardCharacters);
	cout << "\n";

	char gameOption;
	string nextInput;
	bool endGame = false;
	while (!endGame)
	{
		gameOption = getInput(nextInput);
		switch (gameOption)
		{
		case 'E':
			editBoard(boardCharacters, nextInput);
			break;
		case 'Q':
			writeBoard(boardCharacters, nextInput);
			endGame = true;
			break;
		case '?':
			cout << instructions << "\n\n";
			break;
		case 'D':
			displayBoard(boardCharacters);
			cout << "\n";
			break;
		default:
			break;
		}
	}

	return 0;
}

/*********************************************************************
* GETFILENAME
* Prompt user for the file containing the board characters.
*********************************************************************/
void getFileName(string &fileName)
{
	cout << "Where is your board located? ";
	cin >> fileName;
}

/*********************************************************************
* READBOARD
* Reads the characters from the file and save them to boardCharacters 
* array.
*********************************************************************/
void readBoard(string fileName, string boardCharacters[])
{
	ifstream fin(fileName);
	if (fin.fail())
		return;

	for (int i = 0; i < 81 && !fin.fail(); i++)
	{
		fin >> boardCharacters[i];
	}
	
	fin.close();
}

/*********************************************************************
* GETINPUT
* Checks whether gameOption is valid input and prompts for more 
* gameOption.
*********************************************************************/
char getInput(string &nextInput)
{
	cout << "> ";
	char gameOption;
	cin >> gameOption;

	// Check if gameOption is valid.
	if (!(gameOption == '?' ||
		gameOption == 'D' || 
		gameOption == 'E' || 
		gameOption == 'S' || 
		gameOption == 'Q'))
	{
		cout << "Invalid input." << endl;
		return -1;
	}

	switch (gameOption)
	{
	case '?':
		nextInput = gameOption;
		break;
	case 'D':
		nextInput = gameOption;
		break;
	case 'E':
		cout << "What are the coordinates of the square: ";
		cin >> nextInput;
		break;
	case 'S':
		nextInput = gameOption;
		break;
	case 'Q':
		cout << "What file would you like to write your board to: ";
		cin >> nextInput;
		break;
	default:
		break;
	}
	return gameOption;
}

/*********************************************************************
* EDITBOARD
* Computes the index of character to be substituted by using colNum
* and rowNum variable. Then substitutes the character with a new 
* value if the character is a white space.
*********************************************************************/
string editBoard(string boardCharacters[], string input)
{
	char text[3];
	for (int i = 0; i < input.length(); i++)
		text[i] = input[i];

	int colNum = text[0] - 64;
	int rowNum = text[1] - 48;

	// This section finds indexes in the boardCharacters array.
	int index = colNum + rowNum;
	switch (rowNum)
	{
	case 1:
		index -= 2;
		break;
	case 2:
		index += 6;
		break;
	case 3:
		index += 14;
		break;
	case 4:
		index += 22;
		break;
	case 5:
		index += 30;
		break;
	case 6:
		index += 38;
		break;
	case 7:
		index += 46;
		break;
	case 8:
		index += 54;
		break;
	case 9:
		index += 62;
		break;
	}

	if (boardCharacters[index] == " ")
	{
		char value;
		cout << "What is the value at '" << input << "': ";
		cin >> value;
		cout << "\n";
		boardCharacters[index] = value;
		return "a";
	}
	else
	{
		cout << "ERROR: Square '" << input << "' is filled\n\n";
		return "b";
	}
}

/*********************************************************************
* WRITEBOARD
* Copy characters in boardCharacters array to a file.
*********************************************************************/
void writeBoard(string boardCharacters[], string fileName)
{
	ofstream fout(fileName);
	if (fout.fail())
		return;

	for (int i = 0; i < 81; i++)
		if (boardCharacters[i] == " ")
			boardCharacters[i] = "0";

	int i = 0;
	for (int i = 0; i < 81 && !fout.fail(); i++)
		fout << boardCharacters[i] << " ";

	fout.close();
	cout << "Board written successfully\n";
}

/*********************************************************************
* DISPLAYBOARD
* Draws a sukodu board on the screen with characters.
*********************************************************************/
void displayBoard(string boardCharacters[])
{
	cout << "   A B C D E F G H I\n";

	for (int i = 0; i < 81; i++)
		if (boardCharacters[i] == "0")
			boardCharacters[i] = " ";

	int rowCount = 1;
	int colCount = 0;
	cout << rowCount << " ";
	for (int i = 1; i <= 81; i++)
	{
		if (colCount == 3)
			cout << "|" << boardCharacters[i - 1];
		else if (colCount == 6)
			cout << "|" << boardCharacters[i - 1];	
		else if (colCount == 9)
		{
			cout << " " << boardCharacters[i - 1];
			colCount = 0;
		}
		else
			cout << " " << boardCharacters[i - 1];
		colCount++;

		if (i % 9 == 0)
		{
			if (rowCount == 3 || rowCount == 6)
				cout << "\n   -----+-----+-----";

			rowCount++;
			if (rowCount != 10)
				cout << "\n" << rowCount << " ";
		}
	}

	cout << "\n";
}