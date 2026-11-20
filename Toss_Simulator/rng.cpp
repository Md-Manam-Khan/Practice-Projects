#include<random>
using namespace std;
using ll = long long;
#include "rng.h"
RNG rng;
RNG::RNG () : engine(random_device{}())
{
}
ll RNG::next (ll lowerBound, ll upperBound)
{
    uniform_int_distribution<ll> dist(lowerBound, upperBound);
    return dist(engine);
}