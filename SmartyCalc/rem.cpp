#include<iostream>
using namespace std;
using ll = long long;
using str = string;
#define line "====="
#include "rem.h"
void rem ()
{
    str num1Str, num2Str;
    choosePoint:
    cout<<"Input two numbers: ";
    cin>>num1Str>>num2Str;
    ll num1, num2, answer;
    num1 = stoi(num1Str);
    num2 = stoi(num2Str);
    if (num2 == 0)
    {
        cout<<"\nRemainder cannot be determined when divided by 0\n\n";
        goto choosePoint;
    }
    answer = num1 % num2;
    cout<<"\n"<<line<<" The remainder after the operation is: "<<answer<<" "<<line;
}