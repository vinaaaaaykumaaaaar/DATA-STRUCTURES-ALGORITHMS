#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> a = {-2, -3, 4, -1, -2, 1, 5, -3};

    int m = INT32_MIN;
    int sum = 0;

    for (int i = 0; i < a.size(); ++i)
    {
        sum = sum + a[i];

        if (sum > m)
        {
            m = sum;
        }

        if (sum < 0)
            sum = 0;
    }

        cout << m << endl;
}