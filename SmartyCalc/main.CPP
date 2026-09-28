#include<iostream>
using namespace std;
using ll = long long;
using str = string;
#define line "====="
#include "add.h"
int main ()
{
    ios::sync_with_stdio(false);
    str choiceString;
    ll choice, answer, x, y;
    cout<<line<<"Welcome to SmartyCalc\n"<<line;
    choosepoint:
    cout<<"\nChoose a function:";
    cout<<"\n1. Addition";
    cout<<"\n\nI choose: ";
    cin>>choiceString;
    choice = stoi(choiceString);
    switch(choice)
    {
        case 1:
        {
            cout<<"\nInput two numbers: ";
            cin>>x>>y;
            answer = add(x, y);
            cout<<"\n\nThe result of addition is: "<<answer;
            break;
        }
        default:
        {
            cout<<"\nYou have chosen a wrong option. Select again";
            goto choosepoint;
        }
    }
}