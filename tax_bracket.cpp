/***********************************************************************
* Program:
*    Assignment 16, If Statements          (e.g. Assignment 10, Hello World)
*    Brother Foushee, CS124
* Author:
*    Caleb Nwokocha
* Summary: 
*    This program asks the user to input their income and then displays 
*    their tax bracket in percentage.
*
*    Estimated:  1.00 hrs   
*    Actual:     0.30 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * The computeTax function accepts the user input from main function and 
 * then returns a value indicating the user tax bracket.
 *********************************************************************/
double computeTax(double income)
{
   if (income > 0 && income < 15100)
      return 10;
   else if (income > 15100 && income < 61300)
      return 15;
   else if (income > 61300 && income < 123700)
      return 25;
   else if (income > 123700 && income < 188450)
      return 28;
   else if (income > 188450 && income < 336550)
      return 33;
   else if (income > 336550)
      return 35;

   return 0;  
}

/**********************************************************************
 * The main function prints out a prompt asking the user to input their 
 * income then calls computerTax function to print out the user tax 
 * bracket. 
 ***********************************************************************/
int main()
{
   double income;

   cout << "Income: ";
   cin >> income;
   cout << "Your tax bracket is " << computeTax(income) << "%\n";

   return 0;
}
