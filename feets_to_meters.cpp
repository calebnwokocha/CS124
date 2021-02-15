/***********************************************************************
* Program:
*    assignment 43, Command Line (e.g. Assignment 10, Hello World)
*    Brother Foushee, CS124
* Author:
*    Caleb Nwokocha
* Summary:
*    This program converts feet to metres.
*
*    Estimated:  0.0 hrs
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>

using namespace std;

/*********************************************************************
* convertFeetToMetres
* This function takes in a feet value and computes the metre equivalence.
*********************************************************************/
float covertFeetToMetres(float feet)
{
    float metres = 0.3048 * feet;
    return metres;
}

/*********************************************************************
* MAIN
* This function feeds convertFeetToMetres to display the equivalence of 
* a feet input in metres.
*********************************************************************/
int main(int argc, char ** argv)
{
    float num1 = atof(argv[1]);
    float num2 = atof(argv[2]);
    float num3 = atof(argv[3]);
    float num4 = atof(argv[4]);
    float num5 = atof(argv[5]);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    cout << num1 << " feet is " << covertFeetToMetres(num1) << " meters\n";
    cout << num2 << " feet is " << covertFeetToMetres(num2) << " meters\n";
    cout << num3 << " feet is " << covertFeetToMetres(num3) << " meters\n";
    cout << num4 << " feet is " << covertFeetToMetres(num4) << " meters\n";
    cout << num5 << " feet is " << covertFeetToMetres(num5) << " meters\n";

    return 0;
}
