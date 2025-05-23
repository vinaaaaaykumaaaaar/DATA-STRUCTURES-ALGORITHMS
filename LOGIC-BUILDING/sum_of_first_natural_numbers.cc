#include<iostream>

using namespace std;

void sum_iterative(int64_t number)
{
    int64_t sum = 0;

    for(int64_t i=1 ; i<=number; i++)
    {
        sum = sum + i;
    }

    cout<<"Sum = "<<sum<<"\n";
}


void sum_formula(int64_t number)
{
    int64_t sum = 0 ;

    sum = (number *  (number + 1)) / 2;

    cout<<"Sum = "<<sum<<"\n";
}

void sum_recursive(int64_t number , int64_t i, int64_t sum)
{
    if(i > number)
    {
        cout<<"Sum = "<<sum<<"\n";
        return ;
    }

    sum = sum + i;
    i++;

    sum_recursive(number , i , sum);

}

int main()
{
    cout<<"Enter the number \n";
    int64_t number;
    cin>>number;
    
    cout<<"--------------- iterative ----------------\n";
    sum_iterative(number);
    cout<<"--------------- formula  ----------------\n";
    sum_formula(number);
    cout<<"--------------- recursive  ----------------\n";
    sum_recursive(number, 1 , 0);

    return 0;
}
