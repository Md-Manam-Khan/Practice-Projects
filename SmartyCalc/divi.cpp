#include<iostream>
#include <iomanip>
using namespace std;
using ll = long long;
using str = string;
#include "divi.h"
void divi ()
{
    str num1Str, num2Str;
    cout<<"Input two numbers: ";
    cin>>num1Str>>num2Str;
    double num1, num2, answer;
    num1 = stoi(num1Str);
    num2 = stoi(num2Str);
    answer = num1 + num2;
    choosePoint:
    if (num2 == 0)
    {
        cout<<"\nDivision operation cannot be performed by 0\n\n";
        goto choosePoint;
    }
    answer = num1 / num2;
    cout<<fixed<<setprecision(3);
    cout<<"\nThe result of division is: "<<answer;
}