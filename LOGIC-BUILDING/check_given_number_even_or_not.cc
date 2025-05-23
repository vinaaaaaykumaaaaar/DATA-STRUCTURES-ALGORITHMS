#include<iostream>

using namespace std;

bool isEven(int64_t number)
{
    int64_t reminder = number % 2 ;

    if(reminder == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}

int main()
{

    cout<<"Enter a number\n";
    int64_t n;

    cin>>n;

    if(isEven(n))
    {
        cout<<"Number is even\n";
    }
    else
    {
        cout<<"Number is odd\n";
    }

    return 0;

}
