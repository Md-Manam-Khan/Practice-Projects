#include<iostream>
#include<string>
#include<vector>
using namespace std;
using ll = long long;
using str = string;
#define line "====="
#include "toss.h"
#include "input.h"
#include "names.h"
#include "anim.h"
#include "rng.h"
#include "banner.h"
#include "logger.h"
void toss ()
{
    ll count, winner;
    count = readInt("Number of participants (2 or more): ", 2, 1000);
    vector<str> names = readParticipants(count);
    flipAnimation();
    winner = rng.next(0, count - 1);
    printBanner("Winner: " + names[winner]);
    logToFile("Regular toss | participants: " + to_string(count) + " | winner: " + names[winner]);
}