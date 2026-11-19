#include<iostream>
#include<string>
#include<chrono>
#include<limits>
#include<random>
using namespace std;
using namespace std::chrono;
using ll = long long;
using str = string;
#define line "====="
#include "color.h"
#include "play.h"
#include "rng.h"
#include "streak.h"
#include "praise.h"
const str cheatCode = "ManamKnowsTheNumber";
void playRound (ll guessLimit, ll upperLimit)
{
    ll attempt, guessesLeft, guessValue, randomNumber, secondsTaken;
    str raw;
    bool won;
    uniform_int_distribution<ll> dist(1, upperLimit);
    randomNumber = dist(gen);
    guessesLeft = guessLimit;
    attempt = 0;
    won = false;
    if (streakCounter.getCurrent() > 0)
    {
        cout<<Color::cyan<<"Current streak: "<<streakCounter.getCurrent()<<" (best: "<<streakCounter.getBest()<<")"<<Color::reset<<"\n";
    }
    cout<<"You have "<<guessLimit<<" guesses\n";
    cout<<"Range: 1 to "<<upperLimit<<"\n";
    auto start = steady_clock::now();
    while (guessesLeft > 0)
    {
        cout<<"\nGuesses remaining: "<<guessesLeft<<"\nYour guess: ";
        if (!(cin>>raw))
        {
            if (cin.eof())
            {
                cout<<Color::red<<"\nInput stream closed, ending round."<<Color::reset<<"\n";
                return;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<Color::red<<"Invalid input, that guess was not counted."<<Color::reset<<"\n";
            continue;
        }
        if (raw == cheatCode)
        {
            cout<<Color::yellow<<"The number is: "<<randomNumber<<Color::reset<<"\n";
            continue;
        }
        try
        {
            size_t parsedPos;
            guessValue = stoll(raw, &parsedPos);
            if (parsedPos != raw.size())
            {
                throw invalid_argument("format");
            }
        }
        catch (...)
        {
            cout<<Color::red<<"Invalid number, that guess was not counted."<<Color::reset<<"\n";
            continue;
        }
        attempt++;
        guessesLeft--;
        if (guessValue == randomNumber)
        {
            cout<<Color::green<<successMessage(randomNumber)<<Color::reset<<"\n";
            won = true;
            streakCounter.recordWin();
            break;
        }
        else if (guessValue > randomNumber)
        {
            cout<<Color::red<<"Your guess is higher than the number."<<Color::reset<<"\n";
        }
        else
        {
            cout<<Color::red<<"Your guess is lower than the number."<<Color::reset<<"\n";
        }
    }
    auto end = steady_clock::now();
    secondsTaken = duration_cast<seconds>(end - start).count();
    if (won)
    {
        cout<<"\n"<<line<<" Solved in "<<attempt<<" attempts, "<<secondsTaken<<" seconds "<<line;
    }
    else
    {
        cout<<"\n"<<Color::red<<line<<" Out of guesses! The number was: "<<randomNumber<<" "<<line<<Color::reset;
        streakCounter.recordLoss();
    }
}