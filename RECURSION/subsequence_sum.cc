#include <iostream>
#include <vector>

using namespace std;

void calculate_sum(int index, vector<int> &arr, vector<int> &current, int target_sum, int currSum)
{
    if (index == arr.size())
    {
        if (currSum == target_sum)
        {
            for (auto c : current)
                cout << c << " ";
            cout << endl;
        }
        return;
    }

    // take
    current.push_back(arr[index]);
    calculate_sum(index + 1, arr, current, target_sum, currSum + arr[index]);

    // not take
    current.pop_back();
    calculate_sum(index + 1, arr, current, target_sum, currSum);
}

// call it like: calculate_sum(0, arr, current, 3, 0);

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    vector<int> current;

    calculate_sum(0, arr, current, 3, 0);

    return 0;
}