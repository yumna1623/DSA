#include<iostream>
using namespace std;

int Stack[4];
int top=0;

void push(){
    int value;
    cout<<"Enter value to push : ";
    cin>>value;

    if(top==10){
    cout<<"Stack overflow";
    return;
    }
    Stack[top]=value;
    top++;
}
void peek(){

    if(top==0){
        cout<<"Stack underflow";
    }
    else{
        cout<<"Top element is "<<Stack[top-1]<<"\n";
    }
}
void pop(){
    if(top==0){
        cout<<"Stack underflow";
    }
    else{
        top--;
        cout << "Popped value: " << Stack[top]<<"\n";
    }
}



void print(){
    if (top == 0) {
        cout << "Stack is empty\n";
        return;
    }
    for (int i = top - 1; i >= 0; i--) { 
        cout << Stack[i] << "\n";
    }
}


int main() {
    for (int i = 0; i < 4; i++) {
        push();
    }
    
    print();
    int popChoice;
    cout << "Enter 1 to pop: ";
    cin >> popChoice;
    
    if (popChoice == 1) {
        pop();
        peek();
        print();
    }
}
