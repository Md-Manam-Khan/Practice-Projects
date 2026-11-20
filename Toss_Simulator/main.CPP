#include<iostream>
using namespace std;
using ll = long long;
using str = string;
#define line "====="
#include "input.h"
#include "rules.h"
#include "toss.h"
#include "ranked.h"
#include "series.h"
#include "stats.h"
#include "choose.h"
#include "bye.h"
int main ()
{
    ios::sync_with_stdio(false);
    ll choice;
    cout<<line<<" Welcome to Toss Simulator "<<line<<"\n\n";
    printRules();
    choosepoint:
    cout<<"\nChoose a mode:";
    cout<<"\n1. Regular toss";
    cout<<"\n2. Ranked elimination";
    cout<<"\n3. Best of series";
    cout<<"\n4. Head-to-head stats";
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
            toss();
            break;
        }
        case 2:
        {
            ranked();
            break;
        }
        case 3:
        {
            series();
            break;
        }
        case 4:
        {
            stats();
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