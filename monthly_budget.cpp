/***********************************************************************
* Program:
*    Assignment 11, Monthly Budget          (e.g. Assignment 10, Hello World)
*    Brother Foushee, CS124
* Author:
*    Caleb Nwokocha
* Summary: 
*    This program outputs my monthly budget in a tabular fashion,
*    "Items" on the left column, and "Projected" on the right column.
kk*
*    Estimated:  3.00 hrs   
*    Actual:     1.39 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * This function, main, displays a tabular view of a monthly budget.
 ***********************************************************************/
int main()
{
   float income = 1000.00;
   float taxes = 100.00;
   float tithing = 100.00;
   float living = 650.00;
   float other = 90.00;
   float delta  = 60.00;

   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
         cout << "\tItem           Projected\n"
         << "\t=============  ==========\n"
	 << "\tIncome         $" << setw(9) << income << "\n" 
	 << "\tTaxes          $" << setw(9) << taxes << "\n"
         << "\tTithing        $" << setw(9) << tithing << "\n"
         << "\tLiving         $" << setw(9) << living << "\n"
         << "\tOther          $" << setw(9) << other << "\n"
         << "\t=============  ==========\n"
	 << "\tDelta          $" << setw(9) << delta << "\n";        
   
   return 0;
}
