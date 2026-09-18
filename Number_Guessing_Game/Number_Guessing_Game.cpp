#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <limits>
#include <cstdlib>
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
const string cheatCode = "ManamKnowsTheNumber";
class StreakCounter
{
private:
    ll current, best;
public:
    StreakCounter() : current(0), best(0) {}
    void recordWin()
    {
        current++;
        if (current > best)
        {
            best = current;
        }
    }
    void recordLoss()
    {
        current = 0;
    }
    ll getCurrent() const
    {
        return current;
    }
    ll getBest() const
    {
        return best;
    }
};
StreakCounter streakCounter;
mt19937 gen(random_device{}());
ll readLL(const string &prompt, ll minValue, ll maxValue)
{
    string raw;
    ll value, pos;
    while (true)
    {
        cout << prompt;
        if (!(cin >> raw))
        {
            if (cin.eof())
            {
                cout << Color::red << "\nInput stream closed, exiting." << Color::reset << "\n";
                exit(0);
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << Color::red << "Invalid input, try again." << Color::reset << "\n";
            continue;
        }
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
string successMessage(ll number)
{
    if (number % 2 == 0)
    {
        return "Congratulations";
    }
    return "Awesome";
}
void printRules()
{
    cout << Color::bold << "Number Guessing Game" << Color::reset << "\n\n";
    cout << "1. A random number is generated between 1 and an upper limit.\n";
    cout << "2. Choose how many guesses you get.\n";
    cout << "3. Each guess tells you whether the number is higher or lower.\n";
    cout << "4. Guess correctly before you run out of attempts.\n";
}
void playRound(ll guessLimit, ll upperLimit)
{
    ll attempt, guessesLeft, guessValue, randomNumber, secondsTaken;
    string raw;
    bool won;
    uniform_int_distribution<ll> dist(1, upperLimit);
    randomNumber = dist(gen);
    guessesLeft = guessLimit;
    attempt = 0;
    won = false;
    if (streakCounter.getCurrent() > 0)
    {
        cout << Color::cyan << "Current streak: " << streakCounter.getCurrent() << " (best: " << streakCounter.getBest() << ")" << Color::reset << "\n";
    }
    cout << "You have " << guessLimit << " guesses\n";
    cout << "Range: 1 to " << upperLimit << "\n";
    auto start = steady_clock::now();
    while (guessesLeft > 0)
    {
        cout << "\nGuesses remaining: " << guessesLeft << "\nYour guess: ";
        if (!(cin >> raw))
        {
            if (cin.eof())
            {
                cout << Color::red << "\nInput stream closed, ending round." << Color::reset << "\n";
                return;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << Color::red << "Invalid input, that guess was not counted." << Color::reset << "\n";
            continue;
        }
        if (raw == cheatCode)
        {
            cout << Color::yellow << "The number is: " << randomNumber << Color::reset << "\n";
            continue;
        }
        try
        {
            size_t parsedPos;
            guessValue = stoll(raw, &parsedPos);
            if (parsedPos != raw.size())
            {
                throw invalid_argument("format");
            }
        }
        catch (...)
        {
            cout << Color::red << "Invalid number, that guess was not counted." << Color::reset << "\n";
            continue;
        }
        attempt++;
        guessesLeft--;
        if (guessValue == randomNumber)
        {
            cout << Color::green << successMessage(randomNumber) << Color::reset << "\n";
            won = true;
            streakCounter.recordWin();
            break;
        }
        else if (guessValue > randomNumber)
        {
            cout << Color::red << "Your guess is higher than the number." << Color::reset << "\n";
        }
        else
        {
            cout << Color::red << "Your guess is lower than the number." << Color::reset << "\n";
        }
    }
    auto end = steady_clock::now();
    secondsTaken = duration_cast<seconds>(end - start).count();
    if (won)
    {
        cout << "\nSolved in " << attempt << " attempts, " << secondsTaken << " seconds.\n";
    }
    else
    {
        cout << Color::red << "\nOut of guesses! The number was: " << randomNumber << Color::reset << "\n";
        streakCounter.recordLoss();
    }
}
void runDifficultyMenu()
{
    ll difficulty, guessLimit, upperLimit;
    while (true)
    {
        cout << "\nChoose difficulty:\n1. Easy (1-100, 20 guesses)\n2. Medium (1-1000, 15 guesses)\n";
        cout << "3. Hard (1-10000, 10 guesses)\n4. Custom\n5. Back to main menu\n";
        difficulty = readLL("Choice: ", 1, 5);
        switch (difficulty)
        {
            case 1:
            {
                playRound(20, 100);
                break;
            }
            case 2:
            {
                playRound(15, 1000);
                break;
            }
            case 3:
            {
                playRound(10, 10000);
                break;
            }
            case 4:
            {
                upperLimit = readLL("Upper limit (must be at least 2): ", 2, 1000000000);
                guessLimit = readLL("Number of guesses allowed: ", 1, 1000000);
                playRound(guessLimit, upperLimit);
                break;
            }
            case 5:
            {
                return;
            }
        }
        ll again = readLL("\nPlay another round? 1. Yes 2. No: ", 1, 2);
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
        cout << "\n1. Start\n2. Exit\n";
        choice = readLL("Choice: ", 1, 2);
        if (choice == 2)
        {
            cout << Color::cyan << "See you soon, bye!" << Color::reset << "\n";
            return 0;
        }
        runDifficultyMenu();
    }
}