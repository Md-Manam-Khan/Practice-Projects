#include<iostream>
using namespace std;
using ll = long long;
using str = string;
#define line "====="
#include "color.h"
#include "banner.h"
void printBanner (const str &text)
{
    cout<<"\n"<<Color::green<<Color::bold<<line<<" "<<text<<" "<<line<<Color::reset;
}