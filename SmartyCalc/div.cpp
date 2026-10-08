#include<iostream>
using namespace std;
using ll = long long;
#include "div.h"
#include "choose.h"
void div ()
{
    ll x, y, answer;
    cout<<"Input two numbers: ";
    cin>>x>>y;
    if (x == 0)
    {
        cout<<"\n0 cannot be divided";
        choose();
    }
    answer = x / y;
    cout<<"\nThe result of division is: "<<answer;
}