#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool lemonade(vector<int> &l)
{
    int five = 0, ten = 0;

    for (int i = 0; i < l.size(); i++)
    {
        if (l[i] == 5)
            five++;
        else if (l[i] == 10)
        {
            if (five)
                ten++, five--;
            else
                return false;
        }
        else
        {
            if (five && ten)
                ten--, five--;
            else if (five >= 3)
                five -= 3;
            else
                return false;
        }
    }

    return true;
}

int main()
{
    vector<int> b = {5, 5, 5, 10, 20, 20};
    cout << lemonade(b) << endl;
    return 0;
}