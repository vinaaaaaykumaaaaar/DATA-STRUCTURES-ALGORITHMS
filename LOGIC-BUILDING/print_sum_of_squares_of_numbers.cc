#include <iostream>
#include <math.h>

using namespace std;

void print_sum_of_squares(int64_t number)
{
    int64_t sum = 0;
    for(int64_t i=1; i<= number; i++)
    {
        sum += i * i;
    }

    cout<<"Sum = "<<sum<<"\n";
}

void print_sum_of_squares_using_pow(int64_t number)
{
    int64_t i = 1, sum = 0;
    while(i<=number)
    {
        sum += pow(i, 2);
        i++;
    }

    cout<<"Sum = "<<sum<<"\n";
}

int main()
{
    cout<<"Enter the number\n";
    int64_t number;
    cin>>number;
    
    cout<<"---------------- without using function(iterative) --------------\n";
    print_sum_of_squares(number);
    cout<<"---------------- with using function(iterative) --------------\n";
    print_sum_of_squares_using_pow(number);

    return 0;
}
