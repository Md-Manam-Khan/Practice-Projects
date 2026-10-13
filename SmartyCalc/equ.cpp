#include<iostream>
#include<iomanip>
using namespace std;
using ll = long long;
using str = string;
#define line "====="
#include "equ.h"
void equ ()
{
    ll i;
    double num1, num2, result, total = 0;
    str equation;
    getline(cin, equation);
    for (i = 0; i < equation.length(); i++)
    {
        if (equation[i] == '+')
        {
            num1 = equation[i - 1] - '0';
            num2 = equation[i + 1] - '0';
            result = num1 + num2;
            total += result;
        }
        else if (equation[i] == '-')
        {
            num1 = equation[i - 1] - '0';
            num2 = equation[i + 1] - '0';
            result = num1 - num2;
            total -= result;
        }
        else if (equation[i] == '*')
        {
            num1 = equation[i - 1] - '0';
            num2 = equation[i + 1] - '0';
            result = num1 * num2;
            total *= result;
        }
        else if (equation[i] == '/')
        {
            num1 = equation[i - 1] - '0';
            num2 = equation[i + 1] - '0';
            result = num1 / num2;
            total /= result;
        }
        else
        {
            cout<<"\n"<<line<<" Invalid sign detected! Choose again "<<line<<"\n\n";
        }
    }
    cout<<"\n"<<line<<" The solution of the equation: "<<result<<" "<<line<<"\n\n";
}