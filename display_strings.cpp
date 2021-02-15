/***********************************************************************
* Program:
*    assignment 41, Allocating Memory (e.g. Assignment 10, Hello World)
*    Brother Foushee, CS124
* Author:
*    Caleb Nwokocha
* Summary:
*    This program prompts the user to for a number of character and a 
*    string, then displays the string.
*
*    Estimated:  0.0 hrs
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

/*********************************************************************
* This function allocates text a memory size plus 1 bigger than numchar.
*********************************************************************/
string allocateMem(const int numChar, string text)
{
    string* ptext = new(nothrow) string[numChar + 1];

    for (int i = 0; i < numChar; i++)
        *ptext += text[i];

    return *ptext;
    delete ptext;
    ptext = NULL;
}

/*********************************************************************
* This function prompts the user for a text input and displays the text.
*********************************************************************/
int main()
{
    int numChar = 0;
    string text;

    cout << "Number of characters: ";
    cin >> numChar;
    cin.ignore();

    if (numChar < 0)
    {
        cout << "Allocation failure!\n";
        return -1;
    }
        
    cout << "Enter Text: ";
    getline(cin, text);
    cout << "Text: " << allocateMem(numChar, text) << "\n";

    return 0;
}
