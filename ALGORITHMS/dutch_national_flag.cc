/*
------------------------- D U T C H - N A T I O N A L - F L A G - A L G O R I T H M -------------------------

Theory:

    The Dutch National Flag algorithm is a partitioning / sorting algorithm named after the 
    Dutch flag which has three colors (red , white , and blue) arranged in horizontal bands

    This algorithm was proposed by Edsger W. Dijkstra. It efficiently sorts and array containing
    a limited number of distinct values (originally three) in the linear time O(n) with constant 
    space O(1)

Core properties:
    1. One-pass algorithm with O(n) time complexity
    2. In-place sorting with O(1) space complexity
    3. State with respect to the ordering of elements


Key Concepts:
    - Uses three pointeres to partition the array into regions
    - Creates active regions that grow as we process the array
    - Maintains invariants for each region during processing

Applications:
    1. Sorting arrays with a small, fixed number of distinct values
    2. Core subroutine in Quicksort ( partition functions)
    3. Solving the famous "Sort an array of 0's , 1's and 2's "
    4. Partitioning arrays around a pivot value

*/

#include <iostream>
#include <vector>

using namespace std;

void dutch_national_flag(vector<int>& arr)
{
    int low=0 , mid=0, high = arr.size() - 1;

    while(mid <= high)
    {
        switch(arr[mid])
        {
            case 0:
                swap(arr[low], arr[mid]);
                low++ , mid++ ;
                break;

            case 1:
                mid++;
                break;

            case 2:
                swap(arr[mid], arr[high]);
                high--;
                break;
        }
    }
}

void print_array(const vector<int>& arr)
{
    for(int num : arr)
    {
        cout<<num<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> arr = { 2,0,1,2,1,0,0,2,1,1,0,2 };

    cout<<"Original Array: ";
    print_array(arr);

    dutch_national_flag(arr);

    cout<<"Sorted Array: ";
    print_array(arr);
    
    return 0;
}

