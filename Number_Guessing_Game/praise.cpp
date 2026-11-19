#include<string>
using namespace std;
using ll = long long;
using str = string;
#include "praise.h"
str successMessage (ll number)
{
    if (number % 2 == 0)
    {
        return "Congratulations";
    }
    else if (number % 3 == 0)
    {
        return "Yahoooo";
    }
    else if (number % 5 == 0)
    {
        return "Just mindblowing";
    }
    else if (number % 7 == 0)
    {
        return "Great";
    }
    return "Awesome";
}