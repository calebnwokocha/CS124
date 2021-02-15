/***********************************************************************
* Program:
*    project 02, Monthly Budget          (e.g. Assignment 10, Hello World)
*    Brother Foushee, CS124
* Author:
*    Caleb Nwokocha
* Summary: 
*    This program ask the user for inputs, then displays monthly budget 
*    plan in a tabular format.
*
*    Estimated:  1.0 hrs   
*    Actual:     2.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * The MAIN function contains all the variables needed for the program,
 * It prompts the user for some input, then displays a table show the user 
 * monthly budget. 
 ***********************************************************************/
int main()
{
   float monthlyIncome = 0.00;
   float budgetLivingExpenses = 0.00;
   float actualLivingExpenses = 0.00;
   float budgetTaxes = 0.00;
   float actualTaxes = 0.00;
   float budgetTithe = 0.00;
   float actualTithe = 0.00;
   float budgetOtherExpenses = 0.00;
   float actualOtherExpenses = 0.00;
   
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   cout << "This program keeps track of your monthly budget\n"
        << "Please enter the following:\n"
        << "\tYour monthly income: ";
   cin >> monthlyIncome;
   cout << "\tYour budgeted living expenses: ";
   cin >> budgetLivingExpenses;
   cout << "\tYour actual living expenses: ";
   cin >> actualLivingExpenses;
   cout << "\tYour actual taxes withheld: ";
   cin >> actualTaxes;
   cout << "\tYour actual tithe offerings: ";
   cin >> actualTithe;
   cout << "\tYour actual other expenses: ";
   cin >> actualOtherExpenses;

   cout << "\nThe following is a report on your monthly expenses\n";
   cout << "\tItem                  Budget          Actual\n";
   cout << "\t=============== =============== ===============\n";
   cout << "\tIncome          $    " << setw(7) << monthlyIncome << "    $    " 
        << setw(7) << monthlyIncome << "\n";
   cout << "\tTaxes           $    " << setw(7) << budgetTaxes << "    $    " 
        << setw(7) <<actualTaxes << "\n";
   cout << "\tTithing         $    " << setw(7) << budgetTithe << "    $    " 
        << setw(7) << actualTithe << "\n";
   cout << "\tLiving          $    " << setw(7) << budgetLivingExpenses << "    $    "
        << setw(7) <<  actualLivingExpenses << "\n";
   cout << "\tOther           $    " << setw(7) << budgetOtherExpenses << "    $    "
        << setw(7) << actualOtherExpenses << "\n";
   cout << "\t=============== =============== ===============\n";
   cout << "\tDifference      $    " << setw(7) << 0.00 << "    $    " << setw(7) 
        << 0.00 << "\n";

   return 0;
}
