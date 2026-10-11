#include<iostream>
using namespace std;
using ll = long long;
using str = string;
#define line "====="
#include "mult.h"
void mult ()
{
    str num1Str, num2Str;
    ll num1, num2, answer, choose;
    choosePoint:
    cout<<"Input two numbers: ";
    cin>>num1Str>>num2Str;
    num1 = stoi(num1Str);
    num2 = stoi(num2Str);
    if ((num1 == 0) || (num2 == 0))
    {
        cout<<"\n"<<line<<"Multiplying with 0 will cause the whole result to be zero"<<line<<"\n\n";
        cout<<"Proceed?\n";
        cout<<"1. Yes\n";
        cout<<"2. No, choose again!\n\n";
        cout<<"I choose: \n";
        cin>>choose;
        switch (choose)
        {
            case 1:
            {
                answer = num1 * num2;
                cout<<"\n"<<line<<"The result of multiplication is: "<<line<<answer;
                break;
            }
            case 2:
            {
                goto choosePoint;
                break;
            }
        }
    }
}