#include<iostream>
#include<string>
#include<vector>
using namespace std;
using ll = long long;
using str = string;
#define line "====="
#include "color.h"
#include "ranked.h"
#include "input.h"
#include "names.h"
#include "anim.h"
#include "rng.h"
#include "banner.h"
#include "logger.h"
void ranked ()
{
    ll count, place, index, i;
    str summary;
    count = readInt("Number of participants (2 or more): ", 2, 1000);
    vector<str> pool = readParticipants(count);
    vector<str> standings;
    place = 1;
    while (pool.size() > 1)
    {
        flipAnimation(600);
        index = rng.next(0, static_cast<ll>(pool.size()) - 1);
        cout<<Color::yellow<<"Place "<<place<<": "<<pool[index]<<Color::reset<<"\n";
        standings.push_back(pool[index]);
        pool.erase(pool.begin() + index);
        place++;
    }
    standings.push_back(pool.front());
    printBanner("Final standings");
    summary = "Ranked elimination | participants: " + to_string(count) + " | standings:";
    for (i = 0; i < static_cast<ll>(standings.size()); i++)
    {
        cout<<"\n"<<(i + 1)<<". "<<standings[i];
        summary += " " + to_string(i + 1) + ")" + standings[i];
    }
    logToFile(summary);
}