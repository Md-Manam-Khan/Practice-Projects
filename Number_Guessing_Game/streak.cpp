using ll = long long;
#include "streak.h"
StreakCounter streakCounter;
StreakCounter::StreakCounter () : current(0), best(0)
{
}
void StreakCounter::recordWin ()
{
    current++;
    if (current > best)
    {
        best = current;
    }
}
void StreakCounter::recordLoss ()
{
    current = 0;
}
ll StreakCounter::getCurrent () const
{
    return current;
}
ll StreakCounter::getBest () const
{
    return best;
}