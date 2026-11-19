#include<iostream>
using namespace std;
using ll = long long;
using str = string;
#define line "====="
#include "input.h"
#include "rules.h"
#include "easy.h"
#include "medium.h"
#include "hard.h"
#include "custom.h"
#include "choose.h"
#include "bye.h"
int main ()
{
    ios::sync_with_stdio(false);
    ll choice;
    cout<<line<<" Welcome to Number Guessing Game "<<line<<"\n\n";
    printRules();
    choosepoint:
    cout<<"\nChoose a difficulty:";
    cout<<"\n1. Easy (1-100, 20 guesses)";
    cout<<"\n2. Medium (1-1000, 15 guesses)";
    cout<<"\n3. Hard (1-10000, 10 guesses)";
    cout<<"\n4. Custom";
    cout<<"\n0. Exit";
    choice = readChoice("\n\nI choose: ");
    cout<<"\n";
    switch (choice)
    {
        case 0:
        {
            bye();
            return 0;
        }
        case 1:
        {
            easy();
            break;
        }
        case 2:
        {
            medium();
            break;
        }
        case 3:
        {
            hard();
            break;
        }
        case 4:
        {
            custom();
            break;
        }
        default:
        {
            cout<<"\nYou have chosen a wrong option. Select again\n";
            goto choosepoint;
        }
    }
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
}