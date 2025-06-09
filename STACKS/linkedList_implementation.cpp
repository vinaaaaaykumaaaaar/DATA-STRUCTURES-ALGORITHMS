#include <iostream>
using namespace std;

class Node {

    public :
        int data;
        Node* next;
        Node* prev;

        Node (int val){
            data = val;
            next = nullptr;
            prev = nullptr;
        }
};

class DLL {

    Node* start;
    Node* top;

    public :
        DLL(){
            start = nullptr;
            top = nullptr;
        }


        bool isEmpty(){
            return start == nullptr;
        }


        void push(int val){
            Node* cur = new Node(val);

            if(isEmpty()){
                start = cur;
                top = cur;
            }else{
                top->next = cur;
                cur->prev = top;
                top = cur;
        }

        }

        void pop(){
            Node* cur = top;

            if(isEmpty()){
                cout<<"Stack is empty"<<endl;
                return ;
            }

            else if(top == start){
                top = nullptr;
                start = nullptr;
                delete cur;
            }

            else {
                top->prev->next = nullptr;
                top = cur->prev;
                delete cur;

            }
        }

        void stackSize(){
            int cnt = 0;
            Node* ptr = start;
            while(ptr != nullptr){
                cnt++;
                ptr = ptr->next;
            }
            cout<<cnt<<endl;
        }

        void printStack(){
            Node* ptr = start;

            while(ptr!= nullptr){
                cout<<ptr->data<<" ";
                ptr = ptr->next;
            }
            cout<<endl;
        }


        void topElement(){
            if(isEmpty()){
               cout<<"Stack is empty"<<endl;
            }

            cout<<top->data<<endl;
        }

};

int main(){
    DLL stack;
    stack.push(2);
    stack.push(5);
    stack.push(10);
    stack.printStack();
    stack.topElement();
    stack.stackSize();
    stack.pop();
    stack.printStack();
    stack.topElement();
    stack.stackSize();
    
    return 0;


}

















