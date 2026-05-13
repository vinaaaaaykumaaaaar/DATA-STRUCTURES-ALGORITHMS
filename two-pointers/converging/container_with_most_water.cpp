/*
Given an array heights where each element represents the height of a vertical line,
pick two lines to form a container. Return the maximum area (amount of water) the container can hold.

What is area? Width × height, where width is the distance between walls,
and height is the shorter wall (water overflows at the shorter wall).

example : 
    heights = [3, 4, 1, 2, 2, 4, 1, 3, 2]
output 
    21 :# walls at indices 0 and 7 (both height 3): width=7, height=3, area=21

example :
    heights = [1, 2, 1]
output 
    2  # walls at indices 0 and 2: width=2, height=min(1,1)=1, area=2
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// debug macro

void _debug_print() { cerr << endl; }

template <typename T, typename... Args>
void _debug_print(T t, Args... args)
{
    cerr << t << " ";
    _debug_print(args...);
}

#define debug(...)                             \
    do                                         \
    {                                          \
        cerr << "[" << #__VA_ARGS__ << "] = "; \
        _debug_print(__VA_ARGS__);             \
        cerr << endl;                          \
    } while (0)


int main()
{
    vector<int> arr = {3, 4, 1, 2, 2, 4, 1, 3, 2};

    int left = 0 , right = arr.size() - 1 , height = 0 , width = 0 , area = 0 , max_area = -1 , l_index = -1 , r_index = -1;

    while(left < right)
    {
        height = min(arr[left] , arr[right]);
        width = right - left ; 

        area = height * width; 

        debug( left , right , arr[left] , arr[right] ,  height , width, area ,max_area);

        if(area > max_area)
        {
            max_area = area ; 
            l_index = left;
            r_index = right;
        }

        if(arr[left] < arr[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    cout<<"Maximum area = "<<max_area <<" , left index : "<<l_index<<" , right index : "<<r_index<<endl;

    return 0;
}