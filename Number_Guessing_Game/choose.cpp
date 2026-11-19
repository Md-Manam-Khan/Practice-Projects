#include<iostream>
using namespace std;
using ll = long long;
using str = string;
#define line "====="
#include "choose.h"
#include "input.h"
ll choose ()
{
    ll choice;
    cout<<"\n\nWant to play another round?";
    choosepoint:
    cout<<"\n1. Yes";
    cout<<"\n2. No";
    choice = readChoice("\n\nI choose: ");
    if ((choice != 1) && (choice != 2))
    {
        cout<<"\nYou have chosen a wrong option. Select again\n";
        goto choosepoint;
    }
    return choice;
}