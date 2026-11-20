#pragma once
#include<random>
using ll = long long;
class RNG
{
private:
    std::mt19937 engine;
public:
    RNG ();
    ll next (ll lowerBound, ll upperBound);
};
extern RNG rng;