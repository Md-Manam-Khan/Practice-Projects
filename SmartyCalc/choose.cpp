#include<iostream>
using namespace std;
using ll = long long;
using str = string;
ll choose ()
{
    ll choice;
    str choiceString;
    cout<<"\n\nWant to do some more calculations?";
    choosepoint:
    cout<<"\n1. Yes";
    cout<<"\n2. No";
    cout<<"\n\nI choose: ";
    cin>>choiceString;
    choice = stoi(choiceString);
    if ((choice != 1) && (choice != 2))
    {
        goto choosepoint;
    }
    return choice;
}