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

void getFileName(string& fileName);
void readBoard(string fileName, string boardCharacters[]);
char getInput(string& secondInput);
string editBoard(string boardCharacters[], string input);
void writeBoard(string boardCharacters[], string fileName);
void possibleValues(string boardCharacters[]);
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
		case 'e':
			editBoard(boardCharacters, nextInput);
			break;
		case 'Q':
		case 'q':
			writeBoard(boardCharacters, nextInput);
			endGame = true;
			break;
		case '?':
			cout << instructions << "\n\n";
			break;
		case 'D':
		case 'd':
			displayBoard(boardCharacters);
			cout << "\n";
			break;
		case 'S':
		case 's':
			possibleValues(boardCharacters);
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
void getFileName(string& fileName)
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
char getInput(string& nextInput)
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
	case 'd':
		nextInput = gameOption;
		break;
	case 'E':
	case 'e':
		cout << "What are the coordinates of the square: ";
		cin >> nextInput;
		break;
	case 'S':
	case 's':
		cout << "What are the coordinates of the square: ";
		cin >> nextInput;
		break;
	case 'Q':
	case 'q':
		cout << "What file would you like to write your board to: ";
		cin >> nextInput;
		break;
	default:
		break;
	}
	return gameOption;
}

void possibleValues(string boardCharacters[], string input)
{
	// Copy boardCharacters one dimensional
	// data to rearrangedBoard two 
	// dimensional array.
	string rearrangedBoard[9][9];
	for (int cell = 0; cell < 81; cell++)
	{
		int row = 0;
		if ((cell + 1) % 9 == 0)
			row++;
		rearrangedBoard[row][cell] = boardCharacters[cell];
	}

	char text[3];
	for (int i = 0; i < input.length(); i++)
		text[i] = input[i];

	int colNum = (int)text[0];
	int rowNum = (int)text[1];

	if (colNum == 2 ||
		colNum == 5 ||
		colNum == 8)
		colNum -= 1;
	else if (colNum == 3 ||
		colNum == 6 ||
		colNum == 9)
		colNum -= 2;

	if (rowNum == 2 ||
		rowNum == 5 ||
		rowNum == 8)
		rowNum -= 1;
	else if (rowNum == 3 ||
		rowNum == 6 ||
		rowNum == 9)
		rowNum -= 2;

	int possibleValue1;
	int possibleValue2;
	int possibleValue3;
	int colToRow = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int i = 0; i < 9; i++)
			{
				for (int i = 0; i < 9; i++)
				{
					if (rearrangedBoard[rowNum][colNum] == rearrangedBoard[rowNum][i])
				}
				
				colToRow;
			}
			
			colNum++;
		}

		rowNum++;
	}
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
		string value;
		cout << "What is the value at '" << input << "': ";
		cin >> value;
		cout << "\n";

		/*
		for (int i = 0; i < 9; i++)
		{
			index += 9;
			bool foundSimpliarNum = false;
			if (boardCharacters[index] == value)
			{
				foundSimpliarNum = true;
				cout << "ERROR: Value '" << value << "' in the square is '" << input << "' is invalid\n";
				return;
			}
			else if (foundSimpliarNum == false)
			{
				index -= 9;
			}
		}
		*/




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