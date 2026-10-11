#include<iostream>
#include <iomanip>
using namespace std;
using ll = long long;
using str = string;
#define line "====="
#include "divi.h"
void divi ()
{
    str num1Str, num2Str;
    choosePoint:
    cout<<"Input two numbers: ";
    cin>>num1Str>>num2Str;
    double num1, num2, answer;
    num1 = stoi(num1Str);
    num2 = stoi(num2Str);
    if (num2 == 0)
    {
        cout<<"\n"<<line<<"Division operation cannot be performed by 0"<<line<<"\n\n";
        goto choosePoint;
    }
    answer = num1 / num2;
    cout<<fixed<<setprecision(3);
    cout<<"\n"<<line<<"The result of division is: "<<answer<<line;
}