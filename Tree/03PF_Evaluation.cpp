#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *top = NULL;

int getValue(char ch) {
    switch (ch) {
        // case 'a': return 1;
        // case 'b': return 2;
        // case 'c': return 4;
        // case 'd': return 2;
        // case 'x': return 5;
        // case 'y': return 1;
        case 'a': return 1;
        case 'b': return 2;
        case 'c': return 1;
        case 'd': return 1;
        case 'x': return 1;
        default: return 0;
    }
}

void push(int val) {
    Node *ptr = new Node(); 
    ptr->data = val;
    ptr->next = top;
    top = ptr;
}

float pop() {
    
    int val = top->data;
    Node *temp = top;
    top = top->next;
    delete temp;
    return val;
}

float POSTFIX() {
    string postfix;
    cout << "Enter POSTFIX to evaluate : ";
    cin >> postfix;

    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];
        if (isalpha(ch)) {
            float val = getValue(ch);
            push(val);
        } 

        else if(isdigit(ch)){
            float val = ch - 48;
            push(val);
        }
        else {
        
            float operand2  = pop();
            float operand1 = pop();
            
            float result;

            switch (ch) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': 
                    if (operand2 == 0) {
                        cout << "Cannot divide by zero." << endl;
                        return -1;
                    }
                    result = operand1 / operand2; 
                    break;
                default:
                    cout << "Invalid operator: " << ch << endl;
                    return -1;
            }
            push(result);
        }
    }

    // if (top == NULL) {
    //     cout << "Invalid postfix expression." << endl;
    //     return -1;
    // }

    float finalResult = pop();
    
    cout << "Result = " << finalResult << endl;
    return finalResult;
}

int main()
{
    POSTFIX();
}
// abc*d/+a-bx*5/+