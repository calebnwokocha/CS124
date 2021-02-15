/***********************************************************************
* Program:
*    assignment 40, Multi-dimensional Arrays (e.g. Assignment 10, Hello World)
*    Brother Foushee, CS124
* Author:
*    Caleb Nwokocha
* Summary:
*    This program is a draws a Tic-Tac-Toe board on the screen given a file
*    with characters.
*
*    Estimated:  0.0 hrs
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

/*********************************************************************
* This function reads characters from a file.
*********************************************************************/
void readBoard(char board[][3], char fileName[256])
{
    int numRow = 0;
    
    ifstream fin(fileName);
    if (fin.fail())
    {
        return;
    }
   
    for (int numCol = 0; numCol < 9; numCol++)
    {
        fin >> board[numRow][numCol];
        if (fin.fail())
        {
            return;
        }
        if (board[numRow][numCol] == '.')
            board[numRow][numCol] = ' ';

        if (numCol + 1 % 3 == 0)
        {
            numRow++;
        }
    }
    fin.close();
}

/*********************************************************************
* This function writes characters to a file.
*********************************************************************/
void writeBoard(char board[][3], char fileName[256])
{
    int numRow = 0;

    ofstream fout(fileName);
    if (fout.fail())
    {
        return;
    }

    for (int numCol = 0; numCol < 9; numCol++)
    {
        fout << board[numRow][numCol];
        if (fout.fail())
        {
            return;
        }
        if (board[numRow][numCol] == ' ')
            board[numRow][numCol] = '.';

        if (numCol + 1 % 3 == 0)
        {
            numRow++;
        }
    }

    if (!fout.fail())
    {
        cout << "File written\n";
    }
    fout.close();
}

/*********************************************************************
* This function draw the game board on the screen.
*********************************************************************/
void displayBoard(char board[][3])
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " \n"
        << "---+---+---\n"
        << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " \n"
        << "---+---+---\n"
        << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " \n";
}

/*********************************************************************
* This function prompts the user for a file name then calls other
* functions.
*********************************************************************/
int main()
{
    char sourceFileName[256];
    char destFileName[256];
    char board[3][3];

    cout << "Enter source filename: ";
    cin >> sourceFileName;

    readBoard(board, sourceFileName);
    displayBoard(board);

    cout << "Enter destination filename: ";
    cin >> destFileName;
    writeBoard(board, destFileName);

    return 0;
}
