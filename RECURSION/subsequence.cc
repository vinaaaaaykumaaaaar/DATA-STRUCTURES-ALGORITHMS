#include <iostream>
#include <vector>

using namespace std;

void generate(int i, vector<int> &n, vector<int> &c)
{
    if (i == n.size())
    {

        cout << "i = " << i << " n = " << n.size() << endl;
        for (auto x : c)
            cout << x << " ";
        cout << "\n";
        return;
    }

    c.push_back(n[i]);
    generate(i + 1, n, c);
    c.pop_back();
    generate(i + 1, n, c);
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<int> cur;

    generate(0, arr, cur);
    return 0;
}