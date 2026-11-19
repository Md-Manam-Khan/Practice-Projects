#include<iostream>
using namespace std;
using ll = long long;
using str = string;
#define line "====="
#include "color.h"
#include "rules.h"
void printRules ()
{
    cout<<Color::bold<<"Rules"<<Color::reset<<"\n";
    cout<<"1. A random number is generated between 1 and an upper limit.\n";
    cout<<"2. Choose how many guesses you get.\n";
    cout<<"3. Each guess tells you whether the number is higher or lower.\n";
    cout<<"4. Guess correctly before you run out of attempts.\n";
}