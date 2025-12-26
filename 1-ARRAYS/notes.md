## ARRAY INTRODUCTION 

An array is a collection of items of the same variable type that are stored at contiguous memory locations. It is one of the most popular and simple data structures used in programming.

### BASIC TERMINOLOGIES OF ARRAY 

- #### Array Elements :  Elements are items stored in an array.
- #### Array Index :  Elements are accessed by their indexes. Indexes in most of the programming languages start from 0.

### MEMORY REPRESENTATION IN ARRAY

In an array , all the elements or their references are stored in contiguous memory locations. This allows for the efficient access and manipulation of elements.

### DECLARATION OF ARRAY 

Arrays can be declared in various ways in different languages. For better illustration, below are some language-specific array declarations:

``` cpp
// This array will store integer type element
int arr[5];      

// This array will store char type element
char arr[10];   

// This array will store float type element
float arr[20]; 
```

### INITIALIZATION OF ARRAY 

Arrays can be initialized in different ways in different languages. Below are some language-specific array initialization:

``` cpp
int arr[] = { 1, 2, 3, 4, 5 };
char arr[5] = { 'a', 'b', 'c', 'd', 'e' };
float arr[10] = { 1.4, 2.0, 24, 5.0, 0.0 };
```


### TYPES OF ARRAYS

Arrays can be classified in two ways:

- On the basis of Size
- On the basis of Dimensions

![array-images](https://media.geeksforgeeks.org/wp-content/uploads/20240731124259/Types-of-Arrays.webp)


## DYANAMIC ARRAYS

### Vector in C++ STL

A vector represents a dynamic sized array in the Standard Template Library(STL) that automatically grows when elements are added beyond current capacity.

- A programmer does not have to worry about maintaining the capacity and allocating extra space initially.
- Certain insertions and removals can become slightly costly in terms of time as it internally resizes itself beyond certain predefined limits. If time taken for these operations is super critical, then use of plain arrays in C++ should be preferred.
- Vectors support bound checking by using v.at(i) for accessing an element at index i in a vector

``` cpp
#include <iostream>
#include <vector>
using namespace std;
int main() {
    
    // Declares an empty vector
    vector<int> v1;
    
    // Declares vector with given size
    // and fills it with a value
    vector<int> v2(3, 5);  
    
    // Print items of v2
    for (int x : v2) {
        cout << x << " ";
    }
    
    cout << endl;
    
    // Initializes vector using 
    // initializer list.
    vector<int> v3 = {1, 2, 3};  
    
    // Print items of v3
    for (int x : v3) {
        cout << x << " ";
    }
    
    return 0;
}
```

``` txt 
output 

5 5 5 
1 2 3
```
