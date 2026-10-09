#include<iostream>
using namespace std;
using ll = long long;
using str = string;
#include "sub.h"
void sub ()
{
    str num1Str, num2Str;
    ll num1, num2, answer;
    cout<<"Input two numbers: ";
    cin>>num1Str>>num2Str;
    num1 = stoi(num1Str);
    num2 = stoi(num2Str);
    answer = num1 - num2;
    cout<<"\nThe result of subtraction is: "<<answer;
}