#include<iostream>
#include<string>
#include<limits>
#include<cstdlib>
using namespace std;
using ll = long long;
using str = string;
#define line "====="
#include "color.h"
#include "input.h"
static bool parseLL (const str &raw, ll &value)
{
    size_t parsedPos;
    try
    {
        value = stoll(raw, &parsedPos);
    }
    catch (...)
    {
        return false;
    }
    return parsedPos == raw.size();
}
static str readToken (const str &prompt)
{
    str raw;
    while (true)
    {
        cout<<prompt;
        if (cin>>raw)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return raw;
        }
        if (cin.eof())
        {
            cout<<Color::red<<"\nInput stream closed, exiting."<<Color::reset<<"\n";
            exit(0);
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<Color::red<<"Invalid input, try again."<<Color::reset<<"\n";
    }
}
ll readInt (const str &prompt, ll minValue, ll maxValue)
{
    ll value;
    value = 0;
    while (true)
    {
        if (parseLL(readToken(prompt), value) && (value >= minValue) && (value <= maxValue))
        {
            return value;
        }
        cout<<Color::red<<"Enter a number between "<<minValue<<" and "<<maxValue<<"."<<Color::reset<<"\n";
    }
}
ll readOddInt (const str &prompt, ll minValue, ll maxValue)
{
    ll value;
    while (true)
    {
        value = readInt(prompt, minValue, maxValue);
        if (value % 2 == 0)
        {
            cout<<Color::red<<"Enter an odd number only."<<Color::reset<<"\n";
            continue;
        }
        return value;
    }
}
ll readChoice (const str &prompt)
{
    ll value;
    value = 0;
    while (!parseLL(readToken(prompt), value))
    {
        cout<<Color::red<<"Enter a whole number."<<Color::reset<<"\n";
    }
    return value;
}