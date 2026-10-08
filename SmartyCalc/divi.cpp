#include<iostream>
#include <iomanip>
using namespace std;
using ll = long long;
#include "divi.h"
void divi ()
{
    double x, y, answer;
    choosePoint:
    cout<<"Input two numbers: ";
    cin>>x>>y;
    if (y == 0)
    {
        cout<<"\n0 cannot be divided\n\n";
        goto choosePoint;
    }
    answer = x / y;
    cout<<fixed<<setprecision(3);
    cout<<"\nThe result of division is: "<<answer;
}