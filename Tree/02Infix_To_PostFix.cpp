#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *top = NULL;

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}
void push(int val) {
    Node *ptr = new Node(); 
    ptr->data = val;
    ptr->next = top;
    top = ptr;
}

int pop() {
    if (top == NULL) {
        cout << "Stack is empty." << endl;
        return -1;
    }
    int val = top->data;
    Node *temp = top;
    top = top->next;
    delete temp;
    return val;
}

int Infix_To_Postfix() {
    string infix ;
    string postfix = "";
    cout << "Enter infix to convert to postfix: ";
    cin >> infix;

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];
        if (isalpha(ch) || isdigit(ch)) {
            postfix += ch;
        } 
        else {

            while(top != NULL && precedence(top->data) >= precedence(ch)) {
                postfix += pop();
            }
            push(ch);
            }
        }
        while(top != NULL) {
            postfix += pop();
    }
    cout << "Postfix Expression: " << postfix << endl;    
}





int main()
{
     Infix_To_Postfix();
}
// a+b*c/d-a+b*x/5+
// abc*d/+a-bx*5/+