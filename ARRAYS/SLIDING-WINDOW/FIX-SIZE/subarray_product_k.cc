#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {10, 5, 2, 6};

    int k = 100;

    int max_count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        long long prod = 1;

        for (int j = i; j < arr.size(); j++)
        {
            prod = prod * arr[j];
            if (prod < k)
                max_count++;
            else
                break;
        }
    }

    cout << max_count << endl;
}