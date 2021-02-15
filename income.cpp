/***********************************************************************
* Program:
*    Assignment 12, Income          (e.g. Assignment 10, Hello World)
*    Brother Foushee, CS124
* Author:
*    Caleb Nwokocha
* Summary: 
*    This program will ask a user to input his or her income,
*    then will display the income.
*
*    Estimated:  2.0 hrs   
*    Actual:     1.0 hrs
*      Figuring out how to align user input prompt in the same line 
*      with user text prompt was trick. 
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 This function asks the user for an input as their income,
 store the input in the variable "incomeAmount" and prints out the user income.
 ***********************************************************************/
int main()
{
   float incomeAmount;      // stores user income

   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout <<"	Your monthly income: ";
   cin >> incomeAmount;
   cout <<"Your income is: $" << setw(9) << incomeAmount <<"\n"; 

   return 0;
}
