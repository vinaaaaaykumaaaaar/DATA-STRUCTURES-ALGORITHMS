#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Class to count frequencies using unordered_map (hash table)
class FrequencyCounter
{
public:
    void Frequency(int arr[], int n)
    {
        unordered_map<int, int> map; // Stores frequency of each element

        // Count frequencies of all elements
        for (int i = 0; i < n; i++)
            map[arr[i]]++;

        int maxFreq = 0, minFreq = n;
        int maxEle = 0, minEle = 0;

        // Traverse the map to find elements with max and min frequencies
        for (auto it : map)
        {
            int element = it.first;
            int count = it.second;

            // Update max frequency element
            if (count > maxFreq)
            {
                maxFreq = count;
                maxEle = element;
            }

            // Update min frequency element
            if (count < minFreq)
            {
                minFreq = count;
                minEle = element;
            }
        }

        // Print results
        cout << "The highest frequency element is: " << maxEle << "\n";
        cout << "The lowest frequency element is: " << minEle << "\n";
    }
};

int main()
{
    FrequencyCounter fc;                  // Create object of the class
    int arr[] = {10, 5, 10, 15, 10, 5};   // Sample input array
    int n = sizeof(arr) / sizeof(arr[0]); // Determine length of array
    fc.Frequency(arr, n);                 // Call the function
    return 0;
}
