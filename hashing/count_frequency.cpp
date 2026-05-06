#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr = {1, 3, 2, 1, 3};
    vector<int> hash_array(12, 0);

    for (int i = 0; i < arr.size(); i++)
    {
        /* code */
        hash_array[arr[i]]++;
    }

    for (int i = 0; i < hash_array.size(); i++)
    {
        /* code */
        cout << hash_array[i] << " ";
    }
    cout << endl;

    int no_of_query;
    cin >> no_of_query;

    while (no_of_query--)
    {
        int number;
        cin >> number;

        cout << "Number " << number << " freq is " << hash_array[number] << endl;
    }
}