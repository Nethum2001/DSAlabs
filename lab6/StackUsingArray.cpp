// Online C++ compiler to run C++ program online
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;
#define max 500

class Stack{
    int top;
    
    public:
        int arr[max];
        Stack() {
            top = -1;
        }
        void Push(int x);
        int Pop();
        bool isEmpty();
        bool isFull();
        int StackTop();
        void Display();
};

void Stack::Push(int x){
    if (top >= max-1){
        cout<<"Stack Overflow";
    }
    else{
        arr[++top] = x;
    }
}

bool Stack::isEmpty(){
    if (top<0){
        cout<<"Empty stack!";
        return true;
    }
    else{
        return false;
    }
}

bool Stack::isFull(){
    if (top<(max-1)){
        return false;
    }
    else{
        return true;
    }
}

int Stack::StackTop(){
    if (top>-1){
        return arr[top];
    }
    else{
        cout<<"Empty stack!";
        return -1;
    }
}

int Stack::Pop(){
    if  (isEmpty()){
        cout<<"Stack underflow";
        return 0;
    }
    else{
        top = top - 1;
        return arr[top + 1];
    }
}

void Stack::Display(){
    for (int i=0;i<=top;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    auto start = high_resolution_clock::now();
    class Stack s;
    s.Push(8);
    s.Push(10);
    s.Push(5);
    s.Push(11);
    s.Push(15);
    s.Push(23);
    s.Push(6);
    s.Push(18);
    s.Push(20);
    s.Push(17);
    s.Display();
    s.Pop();
    s.Pop();
    s.Pop();
    s.Pop();
    s.Pop();
    s.Display();
    s.Push(4);
    s.Push(30);
    s.Push(3);
    s.Push(1);
    s.Display();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout<<"Time taken to implement stack = "<<duration.count()<<" microseconds";
    return 0;
}
