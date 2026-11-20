#include<iostream>
#include<fstream>
#include<string>
using namespace std;
using ll = long long;
using str = string;
#define line "====="
#include "color.h"
#include "logger.h"
#include "stamp.h"
void logToFile (const str &entry)
{
    ofstream file(logFileName, ios::app);
    if (!file)
    {
        cout<<Color::red<<"Could not write to "<<logFileName<<Color::reset<<"\n";
        return;
    }
    file<<"["<<timestamp()<<"] "<<entry<<"\n";
}