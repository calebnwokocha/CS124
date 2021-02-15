i/***********************************************************************
* Program:
*    Assignment 25, Loop Design          (e.g. Assignment 10, Hello World)
*    Brother Foushee, CS124
* Author:
*    Caleb Nwokocha
* Summary: 
*    This program use the displayTable function to draw a calendar on 
*    the screen. The user is asked for two inputs (number of day in 
*    the month and month offset).
*
*    Estimated:  10.0 hrs   
*    Actual:     6.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/***********************************************************************
 * The displayTable create a table using arrays to display the calendar.
 **********************************************************************/
void displayTable(int numDays, int offset)
{
   int num = 1;     // Number in the array index.
   string numIndex[6];   // Array of numbers in text format.
   int index = 0;       // Array index number.

   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";
   
   if (offset == 0)
   {
      index = 1;   // Set new index value.
      numIndex[index - 1] = " "; // Set number in previous index. 
      cout  << "  " << setw(2) << numIndex[index - 1];
   } 
   else if (offset == 1)
      {
         index = 2;

	 /* Set and display the number in the previous indexes */
         for (int count = 1; count <= 2; count += 1)
            {
	       numIndex[index - count] = " ";
	       cout << "  " << setw(2) << numIndex[index - count];
            }
      }
      else if (offset == 2)
         {
            index  = 3;
	    for (int count = 1; count <= 3; count += 1)
	    {   
	       numIndex[index - count] = " ";
	       cout << "  " << setw(2) << numIndex[index - count];
            }
	 }
	 else if (offset == 3)
            {
               index = 4;
	       for (int count = 1; count <= 4; count += 1)
               {
		  numIndex[index - count] = " ";
		  cout << "  " << setw(2) << numIndex[index - count];
               }
            }
	    else if (offset == 4)
               {       
                  index = 5; 
		  for (int count = 1; count <= 5; count += 1)
                  { 
		     numIndex[index - count] = " ";
		     cout << "  " << setw(2) << numIndex[index - count];
                  }
                }
                else if (offset == 5)
                   {
                      index = 6;
		      for (int count = 1; count <= 6; count += 1)
                      {
			numIndex[index - count] = " ";
			cout << "  " << setw(2) << numIndex[index - count];
                      }
		   }  
                     else if (offset == 6)
                        {
                           index = 0;
                        }   
   
   numIndex[index] = "1";
   cout << "  " <<setw(2) << numIndex[index];

   for ( ; numDays > 5; numDays--)
      {
         if (index == 6)
            {
               cout << "\n";
	       index = 0;
	       num += 1;
	       numIndex[index] = to_string(num);
	       cout << "  " << setw(2) << numIndex[index];
            }
	 num += 1;
	 numIndex[index] = to_string(num);
	 cout << "  " << setw(2) << numIndex[index];
	 index += 1;
      }
   cout << "\n";
}

/**********************************************************************
 * The main function ask the use to number of day in the month and the 
 * offset, then calls displayTable fucntion.
 ***********************************************************************/
int main()
{
   int numDays;
   int offset;
   cout << "Number of days: ";
   cin >> numDays;
   cout << "Offset: ";
   cin >> offset;
   displayTable(numDays, offset);
   return 0;
}
