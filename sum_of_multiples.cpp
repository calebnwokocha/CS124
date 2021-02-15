/***********************************************************************
* Program:
*    Assignment 23, Loop Syntax          (e.g. Assignment 10, Hello World)
*    Brother Foushee, CS124
* Author:
*    Caleb Nwokocha
* Summary: 
*    This program prompts the user to input a positve natural number,
*    then compute and display the sum of multiples of the number.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * The main function compute the sum of multiples of a natural number.
 ***********************************************************************/
int main()
{
   int multiple;
   cout << "What multiples are we adding? ";
   cin >> multiple;
   int userInput = multiple;
   int multipleSum;

   for (int count = multiple; count < 100; count += multiple)
   {
      multipleSum += count;
   }

   cout << "The sum of multiples of " << userInput << " less than 100 are: " << multipleSum << endl;
   
   return 0;
}
