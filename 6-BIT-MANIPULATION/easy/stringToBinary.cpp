#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int stringToDigits(string number)
{
    int res = 0;

    for (int i = 0; i < number.size(); i++)
    {
        int currentDigit = 0;
        currentDigit = number[i] - '0';

        res = res * 10 + currentDigit;
    }

    return res;
}

string decimalToBinary(int number)
{
    string res = "";

    while (number != 1)
    {
        if (number % 2 == 1)
            res += '1';
        else
            res += '0';
        number = number / 2;
    }

    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string number = "121";

    int convertedNumber = stringToDigits(number);

    string binaryNumber = decimalToBinary(convertedNumber);

    int boolean = stringToDigits(binaryNumber);

    cout << "Boolean format of " << number << " is " << boolean << endl;

    return 0;
}