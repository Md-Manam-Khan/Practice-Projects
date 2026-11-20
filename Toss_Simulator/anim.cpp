#include<iostream>
#include<string>
#include<array>
#include<chrono>
#include<thread>
using namespace std;
using namespace std::chrono;
using ll = long long;
using str = string;
#define line "====="
#include "color.h"
#include "anim.h"
void flipAnimation (ll durationMs)
{
    static const array<str, 4> frames = {"|", "/", "-", "\\"};
    ll frame;
    auto start = steady_clock::now();
    frame = 0;
    cout<<Color::magenta<<"Flipping "<<Color::reset;
    while (duration_cast<milliseconds>(steady_clock::now() - start).count() < durationMs)
    {
        cout<<"\b"<<frames[frame % frames.size()]<<flush;
        frame++;
        this_thread::sleep_for(milliseconds(90));
    }
    cout<<"\b "<<"\n";
}