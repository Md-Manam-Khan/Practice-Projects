#include<iostream>
#include<string>
#include<map>
using namespace std;
using ll = long long;
using str = string;
#define line "====="
#include "stats.h"
#include "input.h"
#include "names.h"
#include "anim.h"
#include "rng.h"
#include "banner.h"
#include "logger.h"
void stats ()
{
    ll tosses, i;
    str a, b, summary;
    a = readName("Player 1 name: ");
    b = readName("Player 2 name: ");
    tosses = readInt("Number of tosses to simulate: ", 1, 100000);
    flipAnimation();
    map<str, ll> wins = {{a, 0}, {b, 0}};
    for (i = 0; i < tosses; i++)
    {
        wins[rng.next(0, 1) == 0 ? a : b]++;
    }
    printBanner("Results after " + to_string(tosses) + " tosses");
    summary = "Head-to-head stats | " + a + " vs " + b + " | tosses: " + to_string(tosses) + " |";
    for (auto &entry : wins)
    {
        double pct = tosses == 0 ? 0.0 : (100.0 * entry.second / tosses);
        cout<<"\n"<<entry.first<<": "<<entry.second<<" wins ("<<pct<<"%)";
        summary += " " + entry.first + ": " + to_string(entry.second);
    }
    logToFile(summary);
}