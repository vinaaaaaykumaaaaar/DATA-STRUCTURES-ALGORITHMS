#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

int main()
{
    unordered_map<string, int> fruits;

    fruits["apple"] = 10;
    fruits["mango"] = 20;
    fruits["oranges"] = 30;

    // Search
    if (fruits.find("mango") != fruits.end())
    {
        cout << "Mango Found" << fruits["mango"] << endl;
    }

    cout << "apples " << fruits["apple"] << endl;
    cout << "mango " << fruits["mango"] << endl;
    cout << "oranges " << fruits["oranges"] << endl;

    return 0;
}