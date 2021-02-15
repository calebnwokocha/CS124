/***********************************************************************
* Program:
*    Assignment 33, Pointer          (e.g. Assignment 10, Hello World)
*    Brother Foushee, CS124
* Author:
*    Caleb Nwokocha
* Summary:
*    This program computes who (among 2 people) will pay the expenses on 
*    a date.
*
*    Estimated:  1.0 hrs
*    Actual:     0.30 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>

using namespace std;

/*********************************************************************
* This function prompts the user for date expense cost, the sum all the
* expenses and return the value to main function.
*********************************************************************/
void date(float *pAccount)
{
	float dinnerCost = 0.0;
	float movieCost = 0.0;
	float iceCreamCost = 0.0;
	float sumTotal = 0.0;

	cout << "Cost of the date:\n";
	cout << "\tDinner:    ";
	cin >> dinnerCost;
	cout << "\tMovie:     ";
	cin >> movieCost;
	cout << "\tIce cream: ";
	cin >> iceCreamCost;

	sumTotal = dinnerCost + movieCost + iceCreamCost;
	*pAccount -= sumTotal;
}

/*********************************************************************
* This function prompts the user of their account balance before date 
* expense, then displays their account balance after date expense. 
*********************************************************************/
int main()
{
	float samBalance = 0.0;
	float sueBalance = 0.0;
	float* pAccount;

	cout << "What is Sam's balance? ";
	cin >> samBalance;
	cout << "What is Sue's balance? ";
	cin >> sueBalance;

	if (samBalance > sueBalance)
		pAccount = &samBalance;
	else
		pAccount = &sueBalance;

	date(pAccount);

	cout << "Sam's balance: $" << samBalance << endl;
	cout << "Sue's balance: $" << sueBalance << endl;

	return 0;
}