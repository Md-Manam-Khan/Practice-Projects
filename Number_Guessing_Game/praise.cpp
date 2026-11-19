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
    return "Awesome";
}