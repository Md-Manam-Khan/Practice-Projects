using ll = long long;
#include "custom.h"
#include "input.h"
#include "play.h"
void custom ()
{
    ll guessLimit, upperLimit;
    upperLimit = readLL("Upper limit (must be at least 2): ", 2, 1000000000);
    guessLimit = readLL("Number of guesses allowed: ", 1, 1000000);
    playRound(guessLimit, upperLimit);
}