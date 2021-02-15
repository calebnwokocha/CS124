/***********************************************************************
* Program:
*    Project 07, Calendar          (e.g. Assignment 10, Hello World)
*    Brother Foushee, CS124
* Author:
*    Caleb Nwokocha
* Summary:
*    This program prompts user for month and year as inputs, then draws a 
*    calendar on the screen.
* 
*    Estimated:  5.0 hrs
*    Actual:     2.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

/*********************************************************************
* This function prompts the user for the month and returns the month.
*********************************************************************/
int getMonth()
{
    int monthNum;
    cout << "Enter a month number: ";
    cin >> monthNum;
    return monthNum;
}

/********************************************************************
* This function prompts the user for the year and returns the year.
********************************************************************/
int getYear()
{
    int year;
    cout << "Enter year: ";
    cin >> year;
    return year;
}

/********************************************************************
* This function check whether the month input from the user is within
* the range of valid inputs.
********************************************************************/
bool isMonthValid(int month)
{
    if (month < 1 || month > 12)
    {
        cout << "Month must be between 1 and 12." << endl;
        return false;
    }
    else
        return true;
}

/*********************************************************************
* This function check whether the year input from the user is within
* the range of valid inputs.
*********************************************************************/
bool isYearValid(int year)
{
    if (year < 1753)
    {
        cout << "Year must be 1753 or later." << endl;
        return false;
    }
    else
        return true;
}

/***********************************************************************
* This function check whether a year is a leap year or not.
***********************************************************************/
bool isLeapYear(int year)
{
    /*
    if (year % 2 == 0)
    {
        return true;
    }
    */
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                return true;
            }
            else
                return false;
        }
        else
            return true;
    }
    else
    {
        return false;
    }
}

/*************************************************************************
* This function sets the number of days for month given the month number
* and the year.
*************************************************************************/
int numOfDays(int monthNum, int year)
{
    if (monthNum == 1 || monthNum == 3 || monthNum == 5 || monthNum == 7 ||
        monthNum == 8 || monthNum == 10 || monthNum == 12)
        return 31;
    else if (monthNum == 4 || monthNum == 9 || monthNum == 11)
        return 30;
    else if (isLeapYear(year) == true && monthNum == 2)
        return 29;
    else if (isLeapYear(year) == false && monthNum == 2)
        return 28;
}

/*********************************************************************
* This function sets the offset of a month.
*********************************************************************/
int computeOffset(int monthNum, int year)
{
    int numDays = 0;
    int offset = 0;
    int yearDifference = year - 1753;
    int yearInput = year;

    // Count how many days has passed since 1753.
    numDays = yearDifference * 366;
    for (; yearDifference >= 0; yearDifference--)
    {
        if (isLeapYear(year) == true)
            ;
        else
            numDays -= 1;
        year -= 1;
    }

    switch (monthNum)
    {
    case 1:
        offset = numDays % 7;
        break;
    case 2:
        offset = (numDays + 31) % 7;
        break;
    case 3:
        if (isLeapYear(yearInput) == true)
            offset = (numDays + (31 + 29)) % 7;
        else
            offset = (numDays + (31 + 28)) % 7;
        break;
    case 4:
        if (isLeapYear(yearInput) == true)
            offset = (numDays + ((31 * 2) + 29)) % 7;
        else
            offset = (numDays + ((31 * 2) + 28)) % 7;
        break;
    case 5:
        if (isLeapYear(yearInput) == true)
            offset = (numDays + ((31 * 2) + 29 + 30)) % 7;
        else
            offset = (numDays + ((31 * 2) + 28 + 30)) % 7;
        break;
    case 6:
        if (isLeapYear(yearInput) == true)
            offset = (numDays + ((31 * 3) + 29 + 30)) % 7;
        else
            offset = (numDays + ((31 * 3) + 28 + 30)) % 7;
        break;
    case 7:
        if (isLeapYear(yearInput) == true)
            offset = (numDays + ((31 * 3) + 29 + (30 * 2))) % 7;
        else
            offset = (numDays + ((31 * 3) + 28 + (30 * 2))) % 7;
        break;
    case 8:
        if (isLeapYear(yearInput) == true)
            offset = (numDays + ((31 * 4) + 29 + (30 * 2))) % 7;
        else
            offset = (numDays + ((31 * 4) + 28 + (30 * 2))) % 7;
        break;
    case 9:
        if (isLeapYear(yearInput) == true)
            offset = (numDays + ((31 * 5) + 29 + (30 * 2))) % 7;
        else
            offset = (numDays + ((31 * 5) + 28 + (30 * 2))) % 7;
        break;
    case 10:
        if (isLeapYear(yearInput) == true)
            offset = (numDays + ((31 * 5) + 29 + (30 * 3))) % 7;
        else
            offset = (numDays + ((31 * 5) + 28 + (30 * 3))) % 7;
        break;
    case 11:
        if (isLeapYear(yearInput) == true)
            offset = (numDays + ((31 * 6) + 29 + (30 * 3))) % 7;
        else
            offset = (numDays + ((31 * 6) + 28 + (30 * 3))) % 7;
        break;
    case 12:
        if (isLeapYear(yearInput) == true)
            offset = (numDays + ((31 * 6) + 29 + (30 * 4))) % 7;
        else
            offset = (numDays + ((31 * 6) + 28 + (30 * 4))) % 7;
        break;
    default:
        break;
    }
    //cout << "\nNumber of days passed since 1753: " << numDays
       // << "\nOffset: " << offset << "\n";
    return offset + 1;
}

/***********************************************************************
 * The displayCalendar function create a table using FOR loopto display 
 * a calendar.
 **********************************************************************/
void displayCalendar(int numDays, int offset)
{
    cout << "  Su  Mo  Tu  We  Th  Fr  Sa" << endl;

    if (offset != 6)
    {
        for (int nspaces = 0; nspaces <= offset; nspaces++)
        {
            cout << "    ";
        }
    }

    int dayOfWeek = offset + 2;

    // Make sure Sunday is the 1st day of the week
    if (dayOfWeek > 7)
        dayOfWeek = 1;
    
    for (int dayOfMonth = 1; dayOfMonth <= numDays; dayOfMonth++)
    {
        cout << setw(4) << dayOfMonth;

        dayOfWeek++;
        if (dayOfWeek > 7)
        {
            cout << endl;
            dayOfWeek = 1;
        }
    }

    if (dayOfWeek != 1)
        cout << endl;
}

/**********************************************************************
 * The main function ask the use to number of day in the month and the
 * offset, then calls displayTable fucntion.
 ***********************************************************************/
int main()
{
    /*int numDays = 0;
    cout << "Number of days: ";
    cin >> numDays;

    int offset = 0;
    cout << "Offset: ";
    cin >> offset;*/

    int month;
    int year;

    do {
        month = getMonth();
    } while (isMonthValid(month) != true);

    do {
        year = getYear();
    } while (isYearValid(year) != true);

    cout << "\n";

    if (month == 1)
        cout << "January";
    else if (month == 2)
        cout << "February";
    else if (month == 3)
        cout << "March";
    else if (month == 4)
        cout << "April";
    else if (month == 5)
        cout << "May";
    else if (month == 6)
        cout << "June";
    else if (month == 7)
        cout << "July";
    else if (month == 8)
        cout << "August";
    else if (month == 9)
        cout << "September";
    else if (month == 10)
        cout << "October";
    else if (month == 11)
        cout << "November";
    else if (month == 12)
        cout << "December";

    cout << ", " << year << "\n";

    displayCalendar(numOfDays(month, year), computeOffset(month, year));

    return 0;
}
