#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int lenght = 0;
    int height = 0;
};

int main()
{
    vector<int> binary_array = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1};

    Solution *sol = new Solution;
    cout << (*sol).height << endl;
    cout << (*sol).lenght << endl;

    return 0;
}