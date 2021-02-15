/***********************************************************************
* Program:
*    Assignment 35, Advanced Conditionals (e.g. Assignment 10, Hello World)
*    Brother Foushee, CS124
* Author:
*    Caleb Nwokocha
* Summary:
*    This program converts academic grade in numerical form to 
*    alphabetical form.
*
*    Estimated:  2.0 hrs
*    Actual:     1.30 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <string>

using namespace std;

/*********************************************************************
* This function uses SWITCH statement to assign a grade letter to a 
* a grade number.
*********************************************************************/
char computeLetterGrade(int grade)
{
    char letterGrade;
    int gradeCohort = grade / 10;
    
    switch (gradeCohort)
    {
        case 10:
        case 9:
            letterGrade = 'A';
            break;
        case 8:
            letterGrade = 'B';
            break;
        case 7:
            letterGrade = 'C';
            break;
        case 6:
            letterGrade = 'D';
            break;
        case 5:
            letterGrade = 'F';
            break;
        default:
            letterGrade = 'F';
            break;
    }
    return letterGrade;
}

/*********************************************************************
* This function uses SWITCH statement to assign a sign to a grade 
* letter.
*********************************************************************/
char computeGradeSign(int grade)
{
    char gradeSign;
    int gradeLastDigit = grade % 10;
    
    switch (gradeLastDigit)
    {
        case 0:
        case 1:
        case 2:
            gradeSign = '-';
            break;
        case 7:
        case 8:
        case 9:
            gradeSign = '+';
            break;
        default:
            gradeSign = '*';
            break;
    }
    return gradeSign;
}

/*********************************************************************
* This function prompts the user for a grade number and outputs the 
* grade letter as well as grade sign equivalence.
*********************************************************************/
int main()
{
    int gradeNum = 0;
    int gradeLastDigit = gradeNum % 10;

    cout << "Enter number grade: ";
    cin >> gradeNum;

    char gradeLetter = computeLetterGrade(gradeNum);
    char gradeSign = computeGradeSign(gradeNum);

    switch (gradeLetter)
    {
        case 'A':
        case 'F':
            cout << gradeNum << "% is " << gradeLetter << "\n";
            break;
        case 'B':
        case 'C':
        case 'D':
            if (gradeSign == '*')
                cout << gradeNum << "% is " << gradeLetter << "\n";
            else
                cout << gradeNum << "% is " << gradeLetter << gradeSign << "\n";
            break;
    }

    return 0;
}
