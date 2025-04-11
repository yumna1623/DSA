// #include <iostream>
// using namespace std;

// struct Node
// {
//     int data;
//     Node *next;
//     Node *left = NULL;
//     Node *right = NULL;
// };
// Node *top = NULL;

// Node *root = NULL;

// int precedence(char ch)
// {
//     switch (ch)
//     {
//     case '+':
//     case '-':
//         return 1;
//     case '*':
//     case '/':
//         return 2;
//     default:
//         return 0;
//     }
// }
// void push(Node *node)
// {
//     node->next = top;
//     top = node;
// }

// Node *pop()
// {

//     Node *node = top;
//     Node *temp = top;
//     top = top->next;
//     delete temp;
//     return node;
// }

// string Infix_To_Postfix()
// {

//     for (int i = 0; i < infix.length(); i++)
//     {
//         char ch = infix[i];
//         if (isalpha(ch) || isdigit(ch))
//         {
//             postfix += ch;
//         }
//         else
//         {

//             while (top != NULL && precedence(top->data) >= precedence(ch))
//             {
//                 postfix += pop()->data;
//             }
//             push(ch);
//         }
//     }
//     while (top != NULL)
//     {
//         postfix += pop();
//     }
//     cout << "Postfix Expression: " << postfix << endl;
// }

// Node *Expression()
// {
//     string expr = Infix_To_Postfix();
//     for (int i = 0; i < expr.length(); i++)

//     {
//         char ch = expr[i];
//         if (isalpha(ch) || isdigit(ch))
//         {
//             push(ch);
//         }
//         else
//         {
//             Node *node = new Node();
//             node->data = ch;
//             node->next = NULL;
//             node->left = pop();
//             node->right = pop();

//             push(node);
//         }
//     }
// }
// void printPostOrder(Node *root)
// {
//     if (root == nullptr)
//         return;
//     printPostOrder(root->left);
//     printPostOrder(root->right);
//     cout << root->data << " ";
// }

// int main()
// {

//     string infix;
//     string postfix = "";
//     cout << "Enter infix to convert to postfix: ";
//     cin >> infix;
    
//     Node *Root = Expression();
//     printPostOrder(Root);
// }



#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node *next;
    Node *left = NULL;
    Node *right = NULL;
};

Node *top = NULL;
string infix;
string postfix = "";

int precedence(char ch)
{
    switch (ch)
    {
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

void push(Node *node)
{
    node->next = top;
    top = node;
}

Node *pop()
{
    if (top == NULL)
        return NULL;
    Node *node = top;
    top = top->next;
    return node;
}

string Infix_To_Postfix()
{
    postfix = "";
    top = NULL; // Clear stack before use

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];
        if (isalpha(ch) || isdigit(ch))
        {
            postfix += ch;
        }
        else
        {
            while (top != NULL && precedence(top->data) >= precedence(ch))
            {
                postfix += pop()->data;
            }
            Node *node = new Node();
            node->data = ch;
            node->next = NULL;
            push(node);
        }
    }

    while (top != NULL)
    {
        postfix += pop()->data;
    }

    return postfix;
}

Node *Expression()
{
    string expr = Infix_To_Postfix();
    top = NULL; // reset stack

    for (int i = 0; i < expr.length(); i++)
    {
        char ch = expr[i];
        if (isalpha(ch) || isdigit(ch))
        {
            Node *node = new Node();
            node->data = ch;
            node->next = NULL;
            push(node);
        }
        else
        {
            Node *node = new Node();
            node->data = ch;
            node->next = NULL;

            Node *right = pop();
            Node *left = pop();
            node->left = left;
            node->right = right;

            push(node);
        }
    }

    return pop(); // Final tree root
}

void printPostOrder(Node *root)
{
    if (root == nullptr)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    cout << "Enter infix to convert to postfix: ";
    cin >> infix;

    Node *Root = Expression();
    cout << "Postorder traversal: ";
    printPostOrder(Root);
    cout << endl;

    return 0;
}

// // a+b*c/d-a+b*x/5
// // abc*d/+a-bx*5/+

// a+b*c




