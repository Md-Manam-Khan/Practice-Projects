#include<iostream>
#include<string>
using namespace std;
using ll = long long;
using str = string;
#define line "====="
#include "color.h"
#include "series.h"
#include "input.h"
#include "names.h"
#include "anim.h"
#include "rng.h"
#include "banner.h"
#include "logger.h"
void series ()
{
    ll rounds, roundsNeeded, played, winnerIndex, champion;
    str names[2] = {readName("Player 1 name: "), readName("Player 2 name: ")};
    rounds = readOddInt("Best of how many tosses (odd number, e.g. 3, 5, 7): ", 1, 99);
    ll wins[2] = {0, 0};
    roundsNeeded = rounds / 2 + 1;
    played = 0;
    while (wins[0] < roundsNeeded && wins[1] < roundsNeeded)
    {
        played++;
        cout<<Color::blue<<"\nRound "<<played<<Color::reset<<"\n";
        flipAnimation(700);
        winnerIndex = rng.next(0, 1);
        wins[winnerIndex]++;
        cout<<names[winnerIndex]<<" takes round "<<played<<" ("<<wins[0]<<" - "<<wins[1]<<")\n";
    }
    champion = wins[0] > wins[1] ? 0 : 1;
    printBanner("Series winner: " + names[champion] + " (" + to_string(wins[champion]) + " - " + to_string(wins[1 - champion]) + ")");
    logToFile("Best of series | " + names[0] + " vs " + names[1] + " | best of " + to_string(rounds) + " | final score: " + names[0] + " " + to_string(wins[0]) + " - " + to_string(wins[1]) + " " + names[1] + " | winner: " + names[champion]);
}