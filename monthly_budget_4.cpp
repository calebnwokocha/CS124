/***********************************************************************
* Program:
*    project 04, Monthly Budget          (e.g. Assignment 10, Hello World)
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
double getIncome()
{
   double income;
   cout << "Please enter the following:\n"
        << "\tYour monthly income: ";
   cin >> income;
   return income;
}

/**********************************************************************
 * The getBudgetLiving function prompts the user to input their budgeted
 * living cost.
 **********************************************************************/
double getBudgetLiving()
{
   double budgetLiving;    
   cout << "\tYour budgeted living expenses: ";
   cin >> budgetLiving;
   return budgetLiving;
}

/*********************************************************************
 * The getActualLiving function prompts the user to input their actual 
 * living cost.
 ********************************************************************/
double getActualLiving()
{
   double actualLiving;  
   cout << "\tYour actual living expenses: ";
   cin >> actualLiving;
   return actualLiving;
}

/**********************************************************************
 * The getActualTax function prompts the user to input their actual tax.
 **********************************************************************/
double getActualTax()
{
   double actualTax;  
   cout << "\tYour actual taxes withheld: ";
   cin >> actualTax;
   return actualTax;
}

/**********************************************************************
 * The getActualTithing function prompts the user to input their actual 
 * tithing.
 *********************************************************************/
double getActualTithing()
{
   double actualTithing;  
   cout << "\tYour actual tithe offerings: ";
   cin >> actualTithing;
   return actualTithing;
}

/**********************************************************************
 * The getActualOther function prompts the user to input their actual 
 * other expenses.
 **********************************************************************/
double getActualOther()
{
   double actualOther;  
   cout << "\tYour actual other expenses: ";
   cin >> actualOther;
   return actualOther;
}

/**********************************************************************
 * The computeTithing function calculates and returns the user tithe
 * based on their income.
 *********************************************************************/ 
double computeTithing(double income)
{	
   return income * 0.1;
}

/*********************************************************************
 * The computeTax function returns the user monthly tax amount.
 *********************************************************************/
double computeTax(double monthlyIncome)
{ 
   double yearlyIncome = monthlyIncome * 12;
   double yearlyTax;

   if (yearlyIncome >= 0 && yearlyIncome < 15100)
   {
      yearlyTax = yearlyIncome * 0.10;
   }
   else if (yearlyIncome >= 15100 && yearlyIncome < 61300)
   {
      yearlyTax = 1510 + 0.15 * (yearlyIncome - 15100);
   }
   else if (yearlyIncome >= 61300 && yearlyIncome < 123700)
   {
      yearlyTax = 8440 + 0.25 * (yearlyIncome - 61300);
   }
   else if (yearlyIncome >= 123700 && yearlyIncome < 188450)
   {
      yearlyTax = 24040 + 0.28 * (yearlyIncome - 123700);
   }
   else if (yearlyIncome >= 188450 && yearlyIncome < 336550)
   {
      yearlyTax = 42170 + 0.33 * (yearlyIncome - 188450);
   }
   else if (yearlyIncome >= 336550)
   {
      yearlyTax = 91043 + 0.35 * (yearlyIncome - 336550);
   }
   else
      yearlyTax = 0;
   
   double monthlyTax = yearlyTax / 12;

   return monthlyTax;
}

/**********************************************************************
 * The display function prints out a tabular view of the user 
 * monthly budget plan.
 **********************************************************************/
void display (double income, 
              double budgetLiving, 
              double actualTax, 
              double actualTithing, 
              double actualLiving, 
              double actualOther)
{
   double budgetTax = computeTax(income);
   double budgetTithing = computeTithing(income);
   double budgetOther = income - budgetTax - budgetTithing - budgetLiving;
   double actualDifference = income - actualTax - actualTithing 
                            - actualLiving - actualOther;
   double budgetDifference = 0;
   
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

   double income = getIncome();
   double budgetLiving = getBudgetLiving();
   double actualLiving = getActualLiving();
   double actualTax = getActualTax();
   double actualTithing = getActualTithing();
   double actualOther = getActualOther();

   display(income, budgetLiving, actualTax, 
           actualTithing, actualLiving, actualOther);

   return 0;
}
