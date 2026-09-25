#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <ctime>
#include <cctype>
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
int baseFromChoice(int choice)
{
    switch (choice)
    {
        case 1: return 2;
        case 2: return 8;
        case 3: return 10;
        case 4: return 16;
        default: return 10;
    }
}
string baseName(int base)
{
    switch (base)
    {
        case 2: return "Binary";
        case 8: return "Octal";
        case 16: return "Hexadecimal";
        default: return "Decimal";
    }
}
bool isValidDigitForBase(char c, int base)
{
    if (base == 2) return c == '0' || c == '1';
    if (base == 8) return c >= '0' && c <= '7';
    if (base == 10) return isdigit(static_cast<unsigned char>(c)) != 0;
    return isdigit(static_cast<unsigned char>(c)) != 0 || (toupper(c) >= 'A' && toupper(c) <= 'F');
}
string readBaseNumber(const string &prompt, int base)
{
    string value;
    while (true)
    {
        cout << Color::cyan << prompt << Color::reset;
        cin >> value;
        size_t start = (!value.empty() && value[0] == '-') ? 1 : 0;
        bool valid = value.size() > start;
        for (size_t i = start; i < value.size(); i++)
        {
            if (!isValidDigitForBase(value[i], base))
            {
                valid = false;
                break;
            }
        }
        if (valid)
        {
            return value;
        }
        cout << Color::red << "Invalid " << baseName(base) << " number. Please try again.\n" << Color::reset;
        clearInput();
    }
}
string convertToBase(ll value, int base)
{
    if (value == 0)
    {
        return "0";
    }
    bool negative = value < 0;
    unsigned long long magnitude = negative ? static_cast<unsigned long long>(-value) : static_cast<unsigned long long>(value);
    const string digits = "0123456789ABCDEF";
    string result;
    while (magnitude > 0)
    {
        result = digits[magnitude % base] + result;
        magnitude /= base;
    }
    return negative ? "-" + result : result;
}
void printBaseMenu()
{
    cout << "\n" << Color::bold << Color::yellow << "----- Select Base -----" << Color::reset << "\n";
    cout << Color::green << " 1." << Color::reset << " Binary\n";
    cout << Color::green << " 2." << Color::reset << " Octal\n";
    cout << Color::green << " 3." << Color::reset << " Decimal\n";
    cout << Color::green << " 4." << Color::reset << " Hexadecimal\n";
    cout << Color::bold << "------------------------" << Color::reset << "\n";
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
    cout << Color::green << " 10." << Color::reset << " Number System Conversion\n";
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
        case 10:
        {
            printBaseMenu();
            int fromChoice = static_cast<int>(readInt("Select source base (1-4): "));
            while (fromChoice < 1 || fromChoice > 4)
            {
                cout << Color::red << "Invalid choice. Please select a number from 1 to 4.\n" << Color::reset;
                fromChoice = static_cast<int>(readInt("Select source base (1-4): "));
            }
            int toChoice = static_cast<int>(readInt("Select target base (1-4): "));
            while (toChoice < 1 || toChoice > 4)
            {
                cout << Color::red << "Invalid choice. Please select a number from 1 to 4.\n" << Color::reset;
                toChoice = static_cast<int>(readInt("Select target base (1-4): "));
            }
            int fromBase = baseFromChoice(fromChoice);
            int toBaseSelected = baseFromChoice(toChoice);
            string input = readBaseNumber("Enter a " + baseName(fromBase) + " number: ", fromBase);
            ll decimalValue = stoll(input, nullptr, fromBase);
            string result = convertToBase(decimalValue, toBaseSelected);
            cout << Color::bold << Color::green << "Result: " << result << Color::reset << "\n";
            logResult(input + " (" + baseName(fromBase) + ") -> " + result + " (" + baseName(toBaseSelected) + ")");
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
        int choice = static_cast<int>(readInt("Choose an option (0-10): "));
        running = performOperation(choice);
    }
    return 0;
}