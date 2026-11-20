#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;
using ll = long long;
using str = string;
#define line "====="
#include "color.h"
#include "names.h"
str readName (const str &prompt)
{
    str name;
    size_t start, end;
    while (true)
    {
        cout<<prompt;
        if (!getline(cin, name))
        {
            cout<<Color::red<<"\nInput stream closed, exiting."<<Color::reset<<"\n";
            exit(0);
        }
        start = name.find_first_not_of(" \t");
        if (start == str::npos)
        {
            cout<<Color::red<<"Name cannot be empty."<<Color::reset<<"\n";
            continue;
        }
        end = name.find_last_not_of(" \t");
        return name.substr(start, end - start + 1);
    }
}
vector<str> readParticipants (ll count)
{
    vector<str> names;
    ll i;
    names.reserve(count);
    for (i = 0; i < count; i++)
    {
        names.push_back(readName("Participant " + to_string(i + 1) + " name: "));
    }
    return names;
}