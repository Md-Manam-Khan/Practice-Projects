#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include <thread>
#include <algorithm>
#include <array>
#include <limits>
#include <map>
#include <ctime>
using namespace std;
using namespace std::chrono;
using ll = long long;
namespace Color
{
    const string reset = "\033[0m";
    const string red = "\033[31m";
    const string green = "\033[32m";
    const string yellow = "\033[33m";
    const string blue = "\033[34m";
    const string magenta = "\033[35m";
    const string cyan = "\033[36m";
    const string bold = "\033[1m";
}
const string logFileName = "toss_results.txt";
class RNG
{
private:
    mt19937 engine;
public:
    RNG() : engine(random_device{}()) {}
    ll next(ll lowerBound, ll upperBound)
    {
        uniform_int_distribution<ll> dist(lowerBound, upperBound);
        return dist(engine);
    }
};
RNG rng;
string timestamp()
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
    return string(buffer);
}
void logToFile(const string &entry)
{
    ofstream file(logFileName, ios::app);
    if (!file)
    {
        cout << Color::red << "Could not write to " << logFileName << Color::reset << "\n";
        return;
    }
    file << "[" << timestamp() << "] " << entry << "\n";
}
ll readInt(const string &prompt, ll minValue, ll maxValue)
{
    string raw;
    ll value, pos;
    while (true)
    {
        cout << prompt;
        if (!(cin >> raw))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << Color::red << "Invalid input, try again." << Color::reset << "\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        try
        {
            size_t parsedPos;
            value = stoll(raw, &parsedPos);
            pos = static_cast<ll>(parsedPos);
            if (pos != static_cast<ll>(raw.size()) || value < minValue || value > maxValue)
            {
                throw invalid_argument("range");
            }
            return value;
        }
        catch (...)
        {
            cout << Color::red << "Enter a number between " << minValue << " and " << maxValue << "." << Color::reset << "\n";
        }
    }
}
ll readOddInt(const string &prompt, ll minValue, ll maxValue)
{
    ll value;
    while (true)
    {
        value = readInt(prompt, minValue, maxValue);
        if (value % 2 == 0)
        {
            cout << Color::red << "Enter an odd number only." << Color::reset << "\n";
            continue;
        }
        return value;
    }
}
string readName(const string &prompt)
{
    string name;
    size_t start, end;
    while (true)
    {
        cout << prompt;
        getline(cin, name);
        start = name.find_first_not_of(" \t");
        if (start == string::npos)
        {
            cout << Color::red << "Name cannot be empty." << Color::reset << "\n";
            continue;
        }
        end = name.find_last_not_of(" \t");
        return name.substr(start, end - start + 1);
    }
}
vector<string> readParticipants(ll count)
{
    vector<string> names;
    ll i;
    names.reserve(count);
    for (i = 0; i < count; i++)
    {
        names.push_back(readName("Participant " + to_string(i + 1) + " name: "));
    }
    return names;
}
void flipAnimation(ll durationMs = 1200)
{
    static const array<string, 4> frames = {"|", "/", "-", "\\"};
    ll frame;
    auto start = steady_clock::now();
    frame = 0;
    cout << Color::magenta << "Flipping " << Color::reset;
    while (duration_cast<milliseconds>(steady_clock::now() - start).count() < durationMs)
    {
        cout << "\b" << frames[frame % frames.size()] << flush;
        frame++;
        this_thread::sleep_for(milliseconds(90));
    }
    cout << "\b " << "\n";
}
void printBanner(const string &text)
{
    cout << "\n" << Color::green << Color::bold << text << Color::reset << "\n";
}
void runRegularToss()
{
    ll count, winner;
    count = readInt("Number of participants (2 or more): ", 2, 1000);
    vector<string> names = readParticipants(count);
    flipAnimation();
    winner = rng.next(0, count - 1);
    printBanner("Winner: " + names[winner]);
    logToFile("Regular toss | participants: " + to_string(count) + " | winner: " + names[winner]);
}
void runRankedElimination()
{
    ll count, place, index, i;
    count = readInt("Number of participants (2 or more): ", 2, 1000);
    vector<string> pool = readParticipants(count);
    vector<string> standings;
    place = 1;
    while (pool.size() > 1)
    {
        flipAnimation(600);
        index = rng.next(0, static_cast<ll>(pool.size()) - 1);
        cout << Color::yellow << "Place " << place << ": " << pool[index] << Color::reset << "\n";
        standings.push_back(pool[index]);
        pool.erase(pool.begin() + index);
        place++;
    }
    standings.push_back(pool.front());
    printBanner("Final standings");
    string summary = "Ranked elimination | participants: " + to_string(count) + " | standings:";
    for (i = 0; i < static_cast<ll>(standings.size()); i++)
    {
        cout << (i + 1) << ". " << standings[i] << "\n";
        summary += " " + to_string(i + 1) + ")" + standings[i];
    }
    logToFile(summary);
}
void runBestOfSeries()
{
    ll rounds, roundsNeeded, played, winnerIndex, champion;
    string names[2] = {readName("Player 1 name: "), readName("Player 2 name: ")};
    rounds = readOddInt("Best of how many tosses (odd number, e.g. 3, 5, 7): ", 1, 99);
    ll wins[2] = {0, 0};
    roundsNeeded = rounds / 2 + 1;
    played = 0;
    while (wins[0] < roundsNeeded && wins[1] < roundsNeeded)
    {
        played++;
        cout << Color::blue << "\nRound " << played << Color::reset << "\n";
        flipAnimation(700);
        winnerIndex = rng.next(0, 1);
        wins[winnerIndex]++;
        cout << names[winnerIndex] << " takes round " << played << " (" << wins[0] << " - " << wins[1] << ")\n";
    }
    champion = wins[0] > wins[1] ? 0 : 1;
    printBanner("Series winner: " + names[champion] + " (" + to_string(wins[champion]) + " - " + to_string(wins[1 - champion]) + ")");
    logToFile("Best of series | " + names[0] + " vs " + names[1] + " | best of " + to_string(rounds) + " | final score: " + names[0] + " " + to_string(wins[0]) + " - " + to_string(wins[1]) + " " + names[1] + " | winner: " + names[champion]);
}
void runHeadToHeadStats()
{
    ll tosses, i;
    string a = readName("Player 1 name: ");
    string b = readName("Player 2 name: ");
    tosses = readInt("Number of tosses to simulate: ", 1, 100000);
    flipAnimation();
    map<string, ll> wins = {{a, 0}, {b, 0}};
    for (i = 0; i < tosses; i++)
    {
        wins[rng.next(0, 1) == 0 ? a : b]++;
    }
    printBanner("Results after " + to_string(tosses) + " tosses");
    string summary = "Head-to-head stats | " + a + " vs " + b + " | tosses: " + to_string(tosses) + " |";
    for (auto &entry : wins)
    {
        double pct = tosses == 0 ? 0.0 : (100.0 * entry.second / tosses);
        cout << entry.first << ": " << entry.second << " wins (" << pct << "%)\n";
        summary += " " + entry.first + ": " + to_string(entry.second);
    }
    logToFile(summary);
}
void printRules()
{
    cout << Color::bold << "Toss Simulator" << Color::reset << "\n";
    cout << "1. Any number of participants can join a Regular or Ranked toss.\n";
    cout << "2. Best of Series and Head-to-Head Stats need exactly two players.\n";
    cout << "3. Names are used only for display and can be anything you like.\n";
    cout << "4. Every result is saved to " << logFileName << " in the current folder.\n";
}
void printMainMenu()
{
    cout << "\n1. Start\n2. Exit\n";
}
void printModeMenu()
{
    cout << "\nChoose a mode:\n";
    cout << "1. Regular toss\n";
    cout << "2. Ranked elimination\n";
    cout << "3. Best of series\n";
    cout << "4. Head-to-head stats\n";
    cout << "5. Back to main menu\n";
}
void runModeLoop()
{
    ll mode, again;
    while (true)
    {
        printModeMenu();
        mode = readInt("Choice: ", 1, 5);
        switch (mode)
        {
            case 1:
            {
                runRegularToss();
                break;
            }
            case 2:
            {
                runRankedElimination();
                break;
            }
            case 3:
            {
                runBestOfSeries();
                break;
            }
            case 4:
            {
                runHeadToHeadStats();
                break;
            }
            case 5:
            {
                return;
            }
        }
        again = readInt("\nPlay another round in this mode? 1. Yes 2. No: ", 1, 2);
        if (again == 2)
        {
            return;
        }
    }
}
int main()
{
    ll choice;
    printRules();
    while (true)
    {
        printMainMenu();
        choice = readInt("Choice: ", 1, 2);
        if (choice == 2)
        {
            cout << Color::cyan << "See you soon, bye!" << Color::reset << "\n";
            return 0;
        }
        runModeLoop();
    }
}