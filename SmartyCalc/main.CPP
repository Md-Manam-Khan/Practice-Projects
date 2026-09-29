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
    cout<<line<<"Welcome to SmartyCalc"<<line<<"\n";
    choosepoint:
    cout<<"\nChoose a function:";
    cout<<"\n1. Addition";
    cout<<"\n0. Exit";
    cout<<"\n\nI choose: ";
    cin>>choiceString;
    cout<<"\n";
    choice = stoi(choiceString);
    switch(choice)
    {
        case 0:
        {
            cout<<line<<"Okay Bye!"<<line;
            return 0;
        }
        case 1:
        {
            cout<<"Input two numbers: ";
            cin>>x>>y;
            answer = add(x, y);
            cout<<"\nThe result of addition is: "<<answer;
            break;
        }
        default:
        {
            cout<<"\nYou have chosen a wrong option. Select again\n";
            goto choosepoint;
        }
    }
}