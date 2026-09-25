#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <ctime>
using namespace std;
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
const string logFileName = "calculator_history.txt";
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
void logResult(const string &line)
{
    ofstream out(logFileName, ios::app);
    if (out.is_open())
    {
        out << "[" << timestamp() << "] " << line << "\n";
        out.close();
    }
}
void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
double readDouble(const string &prompt)
{
    double value;
    while (true)
    {
        cout << Color::cyan << prompt << Color::reset;
        if (cin >> value)
        {
            return value;
        }
        cout << Color::red << "Invalid input. Please enter a valid number.\n" << Color::reset;
        clearInput();
    }
}
ll readInt(const string &prompt)
{
    ll value;
    while (true)
    {
        cout << Color::cyan << prompt << Color::reset;
        if (cin >> value)
        {
            return value;
        }
        cout << Color::red << "Invalid input. Please enter a valid integer.\n" << Color::reset;
        clearInput();
    }
}
string formatNumber(double value)
{
    if (value == static_cast<ll>(value))
    {
        return to_string(static_cast<ll>(value));
    }
    return to_string(value);
}
void printMenu()
{
    cout << "\n" << Color::bold << Color::yellow << "===== Smart Calculator =====" << Color::reset << "\n";
    cout << Color::green << " 1." << Color::reset << " Add        (+)\n";
    cout << Color::green << " 2." << Color::reset << " Subtract   (-)\n";
    cout << Color::green << " 3." << Color::reset << " Multiply   (*)\n";
    cout << Color::green << " 4." << Color::reset << " Divide     (/)\n";
    cout << Color::green << " 5." << Color::reset << " Modulus    (%)\n";
    cout << Color::green << " 6." << Color::reset << " Right Shift(>>)\n";
    cout << Color::green << " 7." << Color::reset << " Left Shift (<<)\n";
    cout << Color::green << " 8." << Color::reset << " Bitwise AND(&)\n";
    cout << Color::green << " 9." << Color::reset << " Bitwise OR (|)\n";
    cout << Color::magenta << " 0." << Color::reset << " Exit\n";
    cout << Color::bold << "=============================" << Color::reset << "\n";
}
bool performOperation(int choice)
{
    switch (choice)
    {
        case 1:
        {
            double a = readDouble("Enter first number: ");
            double b = readDouble("Enter second number: ");
            double result = a + b;
            cout << Color::bold << Color::green << "Result: " << result << Color::reset << "\n";
            logResult(formatNumber(a) + " + " + formatNumber(b) + " = " + formatNumber(result));
            break;
        }
        case 2:
        {
            double a = readDouble("Enter first number: ");
            double b = readDouble("Enter second number: ");
            double result = a - b;
            cout << Color::bold << Color::green << "Result: " << result << Color::reset << "\n";
            logResult(formatNumber(a) + " - " + formatNumber(b) + " = " + formatNumber(result));
            break;
        }
        case 3:
        {
            double a = readDouble("Enter first number: ");
            double b = readDouble("Enter second number: ");
            double result = a * b;
            cout << Color::bold << Color::green << "Result: " << result << Color::reset << "\n";
            logResult(formatNumber(a) + " * " + formatNumber(b) + " = " + formatNumber(result));
            break;
        }
        case 4:
        {
            double a = readDouble("Enter first number: ");
            double b = readDouble("Enter second number: ");
            if (b == 0)
            {
                cout << Color::red << "Error: Division by zero is not allowed.\n" << Color::reset;
                logResult(formatNumber(a) + " / " + formatNumber(b) + " = ERROR (division by zero)");
                break;
            }
            double result = a / b;
            cout << Color::bold << Color::green << "Result: " << result << Color::reset << "\n";
            logResult(formatNumber(a) + " / " + formatNumber(b) + " = " + formatNumber(result));
            break;
        }
        case 5:
        {
            ll a = readInt("Enter first integer: ");
            ll b = readInt("Enter second integer: ");
            if (b == 0)
            {
                cout << Color::red << "Error: Modulus by zero is not allowed.\n" << Color::reset;
                logResult(to_string(a) + " % " + to_string(b) + " = ERROR (mod by zero)");
                break;
            }
            ll result = a % b;
            cout << Color::bold << Color::green << "Result: " << result << Color::reset << "\n";
            logResult(to_string(a) + " % " + to_string(b) + " = " + to_string(result));
            break;
        }
        case 6:
        {
            ll a = readInt("Enter integer: ");
            ll b = readInt("Enter shift amount: ");
            if (b < 0)
            {
                cout << Color::red << "Error: Shift amount cannot be negative.\n" << Color::reset;
                logResult(to_string(a) + " >> " + to_string(b) + " = ERROR (negative shift)");
                break;
            }
            ll result = a >> b;
            cout << Color::bold << Color::green << "Result: " << result << Color::reset << "\n";
            logResult(to_string(a) + " >> " + to_string(b) + " = " + to_string(result));
            break;
        }
        case 7:
        {
            ll a = readInt("Enter integer: ");
            ll b = readInt("Enter shift amount: ");
            if (b < 0)
            {
                cout << Color::red << "Error: Shift amount cannot be negative.\n" << Color::reset;
                logResult(to_string(a) + " << " + to_string(b) + " = ERROR (negative shift)");
                break;
            }
            ll result = a << b;
            cout << Color::bold << Color::green << "Result: " << result << Color::reset << "\n";
            logResult(to_string(a) + " << " + to_string(b) + " = " + to_string(result));
            break;
        }
        case 8:
        {
            ll a = readInt("Enter first integer: ");
            ll b = readInt("Enter second integer: ");
            ll result = a & b;
            cout << Color::bold << Color::green << "Result: " << result << Color::reset << "\n";
            logResult(to_string(a) + " & " + to_string(b) + " = " + to_string(result));
            break;
        }
        case 9:
        {
            ll a = readInt("Enter first integer: ");
            ll b = readInt("Enter second integer: ");
            ll result = a | b;
            cout << Color::bold << Color::green << "Result: " << result << Color::reset << "\n";
            logResult(to_string(a) + " | " + to_string(b) + " = " + to_string(result));
            break;
        }
        case 0:
        {
            cout << Color::yellow << "Exiting Smart Calculator. Goodbye!\n" << Color::reset;
            return false;
        }
        default:
        {
            cout << Color::red << "Invalid choice. Please select a number from the menu.\n" << Color::reset;
            break;
        }
    }
    return true;
}
int main()
{
    cout << Color::bold << Color::blue << "Welcome to Smart Calculator!\n" << Color::reset << "Supports +, -, *, /, %, >>, <<, &, |\n";
    bool running = true;
    while (running)
    {
        printMenu();
        int choice = static_cast<int>(readInt("Choose an option (0-9): "));
        running = performOperation(choice);
    }
    return 0;
}