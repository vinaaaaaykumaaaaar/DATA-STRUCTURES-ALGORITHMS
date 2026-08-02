#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v1;                       // empty vector
    vector<int> v2(5);                    // size 5, default-initialized to 0;
    vector<int> v3(5, 10);                // size 5 , initialized to 10 ;
    vector<int> v4 = {1, 2, 3, 4, 5};     // initializer list
    vector<int> v5(v4);                   // copy constructor
    vector<int> v6(v4.begin(), v4.end()); // range constructor

    cout << v4.at(1) << endl;

    

    return 0;
}
