/***********************************************************************
* Program:
*    project 03, Monthly Budget          (e.g. Assignment 10, Hello World)
*    Brother Foushee, CS124
* Author:
*    Caleb Nwokocha
* Summary: 
*    This program ask the user for inputs, then displays monthly budget 
*    plan in a tabular format.
*
*    Estimated:  3.0 hrs   
*    Actual:     4.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * The getIncome function prompts the user to input their income.
 *********************************************************************/
float getIncome()
{
   float income;
   cout << "Please enter the following:\n"
        << "\tYour monthly income: ";
   cin >> income;
   return income;
}

/**********************************************************************
 * The getBudgetLiving function prompts the user to input their budgeted
 * living cost.
 **********************************************************************/
float getBudgetLiving()
{
   float budgetLiving;    
   cout << "\tYour budgeted living expenses: ";
   cin >> budgetLiving;
   return budgetLiving;
}

/*********************************************************************
 * The getActualLiving function prompts the user to input their actual 
 * living cost.
 ********************************************************************/
float getActualLiving()
{
   float actualLiving;  
   cout << "\tYour actual living expenses: ";
   cin >> actualLiving;
   return actualLiving;
}

/**********************************************************************
 * The getActualTax function prompts the user to input their actual tax.
 **********************************************************************/
float getActualTax()
{
   float actualTax;  
   cout << "\tYour actual taxes withheld: ";
   cin >> actualTax;
   return actualTax;
}

/**********************************************************************
 * The getActualTithing function prompts the user to input their actual 
 * tithing.
 *********************************************************************/
float getActualTithing()
{
   float actualTithing;  
   cout << "\tYour actual tithe offerings: ";
   cin >> actualTithing;
   return actualTithing;
}

/**********************************************************************
 * The getActualOther function prompts the user to input their actual 
 * other expenses.
 **********************************************************************/
float getActualOther()
{
   float actualOther;  
   cout << "\tYour actual other expenses: ";
   cin >> actualOther;
   return actualOther;
}

/**********************************************************************
 * The computeTithing function calculates and returns the user tithe
 * based on their income.
 *********************************************************************/ 
float computeTithing(float income)
{	
   return income * 0.1;
}

/*********************************************************************
 * The computeTax function returns the user tax amount.
 *********************************************************************/
float computeTax(float income)
{
   return 0.0;
}

/**********************************************************************
 * The display function prints out a tabular view of the user 
 * monthly budget plan.
 **********************************************************************/
void display (float income, 
              float budgetLiving, 
              float actualTax, 
              float actualTithing, 
              float actualLiving, 
              float actualOther)
{
   float budgetTax = computeTax(income);
   float budgetTithing = computeTithing(income);
   float budgetOther = income - budgetTax - budgetTithing - budgetLiving;
   float actualDifference = income - actualTax - actualTithing 
                            - actualLiving - actualOther;
   float budgetDifference = 0;
   
   cout << "\nThe following is a report on your monthly expenses\n"
        << "\tItem                  Budget          Actual\n"
        << "\t=============== =============== ===============\n";
   cout << "\tIncome          $    " << setw(7) << income 
        << "    $    " << setw(7) << income << "\n";
   cout << "\tTaxes           $    " << setw(7) << budgetTax 
        << "    $    " << setw(7) << actualTax << "\n";
   cout << "\tTithing         $    " << setw(7) << budgetTithing 
        << "    $    " << setw(7) << actualTithing << "\n";
   cout << "\tLiving          $    " << setw(7) << budgetLiving 
        << "    $    " << setw(7) << actualLiving << "\n";
   cout << "\tOther           $    " << setw(7) << budgetOther 
        << "    $    " << setw(7) << actualOther << "\n";
   cout << "\t=============== =============== ===============\n";
   cout << "\tDifference      $    " << setw(7) << budgetDifference 
        << "    $    " << setw(7) << actualDifference << "\n";
}

/***********************************************************************
 * The program starts in the main function. Main function instantiates
 * other functions in the program.
 * ********************************************************************/
int main()
{
   cout << "This program keeps track of your monthly budget\n";

   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   float income = getIncome();
   float budgetLiving = getBudgetLiving();
   float actualLiving = getActualLiving();
   float actualTax = getActualTax();
   float actualTithing = getActualTithing();
   float actualOther = getActualOther();

   display(income, budgetLiving, actualTax, 
           actualTithing, actualLiving, actualOther);

   return 0;
}
