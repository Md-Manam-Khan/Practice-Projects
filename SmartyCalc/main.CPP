#include<iostream>
using namespace std;
using ll = long long;
using str = string;
#define line "====="
#include "add.h"
#include "sub.h"
#include "mult.h"
#include "divi.h"
#include "choose.h"
#include "bye.h"
int main ()
{
    ios::sync_with_stdio(false);
    str choiceString;
    ll choice, answer, x, y;
    cout<<line<<"Welcome to SmartyCalc"<<line<<"\n";
    choosepoint:
    cout<<"\nChoose a function:";
    cout<<"\n1. Addition";
    cout<<"\n2. Subtraction";
    cout<<"\n3. Multiplication";
    cout<<"\n4. Division";
    cout<<"\n0. Exit";
    cout<<"\n\nI choose: ";
    cin>>choiceString;
    cout<<"\n";
    choice = stoi(choiceString);
    switch(choice)
    {
        case 0:
        {
            bye();
            return 0;
        }
        case 1:
        {
            add();
            choice = choose();
            switch (choice)
            {
                case 1:
                {
                    goto choosepoint;
                    break;
                }
                default:
                {
                    cout<<"\n";
                    bye();
                    break;
                }
            }
            break;
        }
        case 2:
        {
            sub();
            choice = choose();
            switch (choice)
            {
                case 1:
                {
                    goto choosepoint;
                    break;
                }
                default:
                {
                    cout<<"\n";
                    bye();
                    break;
                }
            }
            break;
        }
        case 3:
        {
            mult();
            choice = choose();
            switch (choice)
            {
                case 1:
                {
                    goto choosepoint;
                    break;
                }
                default:
                {
                    cout<<"\n";
                    bye();
                    break;
                }
            }
            break;
        }
        case 4:
        {
            divi();
            choice = choose();
            switch (choice)
            {
                case 1:
                {
                    goto choosepoint;
                    break;
                }
                default:
                {
                    cout<<"\n";
                    bye();
                    break;
                }
            }
            break;
        }
        default:
        {
            cout<<"\nYou have chosen a wrong option. Select again\n";
            goto choosepoint;
        }
    }
}