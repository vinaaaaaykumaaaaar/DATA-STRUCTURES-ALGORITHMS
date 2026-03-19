#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // priniting the vector directly with out the for loop ( using for each )
    vector<int> a = {1, 2, 3, 4, 5};
    for (auto x : a)
        cout << x << " ";

    return 0;
}