/***********************************************************************
* Program:
*    Assignment 13, Expression          (e.g. Assignment 10, Hello World)
*    Brother Foushee, CS124
* Author:
*    Caleb Nwokocha
* Summary: 
*    This program as convert Fahrenheit degree to Celsius.
*
*    Estimated:  0.45 hrs   
*    Actual:     1.00 hrs
*      
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * This function main() asks the user for an input, assigns the input to 
 * fahrenheit variable then calculate and print the celsius conversion.
 ***********************************************************************/
int main()
{
   int fahrenheit = 0;

   cout << "Please enter Fahrenheit degrees: ";
   cin >> fahrenheit;

   float celsius = 5.0 / 9 * ( fahrenheit - 32 );

   cout.setf(ios::fixed);
   cout.precision(0);

   cout << "Celsius: " << celsius << "\n";

   return 0;
}
