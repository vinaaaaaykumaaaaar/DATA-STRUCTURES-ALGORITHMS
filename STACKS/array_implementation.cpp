#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Stack {
    private :
        static const int MAX_SIZE = 100;
        int arr[MAX_SIZE];
        int topIndex;

    public :
        Stack() : topIndex(-1){}

        bool isEmpty() const {
            return (topIndex == - 1);
        }

        bool isFull() const {
            return (topIndex == MAX_SIZE - 1);
        }

        void push(int value){
            if(isFull()){
                cout<<"Stack is full "<<endl;
                return ;
            }
            arr[++topIndex] = value;
            cout<<"Pushed to stack "<<value<<endl;
        }

        void pop(){
            if(isEmpty()){
                cout<<"Stack is empty"<<endl;
                return ;
            }
            cout<<"Poped from stack "<<arr[topIndex]<<endl;
            --topIndex;

        }

        void top(){
            if(isEmpty()){
                cout<<"Stack is empty"<<endl;
                return ;
            }

            cout<<"Top = "<<arr[topIndex]<<endl;
        }

        void display() const {

             if (isEmpty()) {
                  cout << "Stack is empty." << endl;
                  return;
              }
              cout << "Stack elements (top to bottom): ";
              for (int i = topIndex; i >= 0; --i) {
                      cout << arr[i] << " ";
               }
              cout << endl;
        }
     
        
};

int main(){

}
