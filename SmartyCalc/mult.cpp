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
    bool zeroPresent = false;
    choosePoint:
    cout<<"Input two numbers: ";
    cin>>num1Str>>num2Str;
    num1 = stoi(num1Str);
    num2 = stoi(num2Str);
    answer = num1 * num2;
    if (answer == 0)
    {
        zeroPresent = true;
    }
    else
    {
        zeroPresent = false;
    }
    if (zeroPresent)
    {
        choosePoint2:
        cout<<"\n"<<line<<"Multiplying with 0 will cause the whole result to be zero"<<line<<"\n\n";
        cout<<"Proceed?\n";
        cout<<"1. Yes\n";
        cout<<"2. No, choose again\n\n";
        cout<<"I choose: ";
        cin>>choose;
        cout<<"\n";
        switch (choose)
        {
            case 1:
            {
                cout<<"\n"<<line<<"The result of multiplication is: 0"<<line;
                break;
            }
            case 2:
            {
                goto choosePoint;
                break;
            }
            default:
            {
                cout<<"Wrong choice, choose again\n";
                goto choosePoint2;
            }
        }
    }
    else
    {
        cout<<"\n"<<line<<"The result of multiplication is: "<<answer<<line;
    }
}