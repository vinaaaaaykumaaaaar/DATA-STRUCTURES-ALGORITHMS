#include<iostream>

using namespace std;

void print_table(int64_t number)
{
    for(int i=1; i<=10; i++)
    {
        cout<<number<<" * "<<i<<" = "<<number * i<<"\n";
    }
}

void print_table_recursive(int64_t number , int64_t i)
{
    if(i == 11) return ;

    cout<<number <<" * "<<i<<" = "<< number * i <<"\n";
    i++;

    print_table_recursive(number , i);

}

int main()
{
    cout<<"Enter the number of the table to be printed\n";
    
    int64_t number;
    
    cin>>number;

    cout<<"------------------ iterative ---------------------\n";
    print_table(number);
    cout<<"------------------ recursive ---------------------\n";
    print_table_recursive(number , 1);

    return 0;
}
