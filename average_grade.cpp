/***********************************************************************
* Program:
*    Assignment 31, Array Design          (e.g. Assignment 10, Hello World)
*    Brother Foushee, CS124
* Author:
*    Caleb Nwokocha
* Summary:
*    This program computes the average grade in a given set of grades.
*
*    Estimated:  1.0 hrs
*    Actual:     0.30 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>

using namespace std;

/*********************************************************************
* This function prompts the user to input 10 grades.
*********************************************************************/
void getGrades(int grade[], int num)
{
	for (int iGrade = 0; iGrade <= num; iGrade++)
	{
		cout << "Grade " << iGrade + 1 << ": ";
		cin >> grade[iGrade];
	}
}

/*********************************************************************
* This function computes average grade.
*********************************************************************/
int averageGrades(const int grade[])
{
	int sum = 0;
	int average = 0;
	int num = 10;
	for (int i = 0; i <= 9; i++)
	{
		if (grade[i] == -1)
		{
			sum += 0;
			num -= 1;
		}
		else
		{
			sum += grade[i];
		}
	}
	if (num > 0)
	{
		average = sum / num;
		return average;
	}
	else if (num == 0)
		average = 0;
		return average;
}

/*********************************************************************
* The function print the calls other functions and print the average 
* grade.
*********************************************************************/
int main()
{
	int num = 9;
	int grade[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	getGrades(grade, num);
	if (averageGrades(grade) > 0)
		cout << "Average Grade: " << averageGrades(grade) << "%" <<endl;
	else if (averageGrades(grade) == 0)
		cout << "Average Grade: ---%" << endl;
	return 0;
}