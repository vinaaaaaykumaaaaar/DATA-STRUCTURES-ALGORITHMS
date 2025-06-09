#include<iostream>
using namespace std;

class Stack
{
    public :
        int top;
        int arr[100];

    public :
        Stack(){ top = -1;}

        void push(int x){
            if(top>=99) {
                cout<<"Stack overflow"<<endl;
                return ;
            }

            arr[++top] = x;
            cout<<"Pushed "<<x<<endl;
        }

        int pop(){
            if(top<0){
                cout<<"Stack underflow"<<endl;
                return 0;
            }

            return arr[top--];
        }

        int peek(){
            if(top<0){
                cout<<"Stack is empty"<<endl;
                return 0;
            }

            return arr[top];
        }

        bool isEmpty(){
            return (top < 0);
        }

};

int main()
{

    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout<<"Top element is: "<<s.peek()<<endl;

    cout<<"Elements present in stack : ";
    while(!s.isEmpty()){
        cout<<s.pop()<<" ";
    }

    return 0;

}
