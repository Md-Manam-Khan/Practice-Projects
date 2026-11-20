#include<string>
#include<ctime>
using namespace std;
using ll = long long;
using str = string;
#include "stamp.h"
str timestamp ()
{
    time_t now = time(nullptr);
    tm localTime{};
#if defined(_WIN32)
    localtime_s(&localTime, &now);
#else
    localtime_r(&now, &localTime);
#endif
    char buffer[32];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &localTime);
    return str(buffer);
}