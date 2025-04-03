/*
In C++, vectors are used to store elements of similar data types. However, unlike arrays, the size of a vector can grow dynamically.

That is, we can change the size of the vector during the execution of a program as per our requirements.

Vectors are part of the C++ Standard Template Library. To use vectors, we need to include the vector header file in our program.

#include <vector>

Once we include the header file, here's how we can declare a vector in C++:

std::vector<T> vector_name;
The type parameter <T> specifies the type of the vector. It can be any primitive data type such as int, char, float, etc. For example,

vector<int> num;
Here, num is the name of the vector.

Notice that we have not specified the size of the vector during the declaration. This is because the size of a vector can grow dynamically, so it is not necessary to define it.

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<int> vec = {1, 2, 3, 4, 5};

    for (auto x : vec)
    {
        cout << x << " ";
    }
    cout << endl;

    vec.push_back(6);
    vec.push_back(7);

    cout << "Updated vector\n";
    for (auto x : vec)
    {
        cout << x << " ";
    }

    vec.pop_back();
    cout << "\nUpdated vector\n";
    for (auto x : vec)
    {
        cout << x << " ";
    }

    cout << endl;
}