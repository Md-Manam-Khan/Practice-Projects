#include<iostream>
using namespace std;
using ll = long long;
using str = string;
#define line "====="
#include "color.h"
#include "logger.h"
#include "rules.h"
void printRules ()
{
    cout<<Color::bold<<"Rules"<<Color::reset<<"\n";
    cout<<"1. Any number of participants can join a Regular or Ranked toss.\n";
    cout<<"2. Best of Series and Head-to-Head Stats need exactly two players.\n";
    cout<<"3. Names are used only for display and can be anything you like.\n";
    cout<<"4. Every result is saved to "<<logFileName<<" in the current folder.\n";
}