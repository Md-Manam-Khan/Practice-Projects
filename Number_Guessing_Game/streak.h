#pragma once
using ll = long long;
class StreakCounter
{
private:
    ll current, best;
public:
    StreakCounter ();
    void recordWin ();
    void recordLoss ();
    ll getCurrent () const;
    ll getBest () const;
};
extern StreakCounter streakCounter;