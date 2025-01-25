#include <iostream>
using namespace std;

string maxOdd(string s)
{

    for (int i = s.length() - 1; i >= 0; i--)
    {

        if (s[i] % 2 != 0)
        {

            string s1 = s.substr(0, i + 1);

            return s1;
        }
    }

    return "";
}

// Drivers code
int main()
{

    string s = "50497348";
    // string ans = maxOdd(s);

    // Function Call
    //   cout << ans;

    string n = s.substr(0, 4);

    cout << n;
    return 0;
}