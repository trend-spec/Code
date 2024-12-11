#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <ctype.h>
using namespace std;

struct stack1
{
    char data;
    stack1 *next;

} *top = NULL;

struct stack2
{
    int data;
    stack2 *next;

} *top1 = NULL;

int precedence(char op)
{
    if (op == '^')
    {
        return 3;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    else if (op == '+' || op == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void infixprefix(char infix[30])
{
    stack1 *newnode, *temp;
    string p;
    int i = strlen(infix) - 1;
    int l;
    newnode = new stack1;
    newnode->data = ')';
    newnode->next = top;
    top = newnode;

    l = strlen(infix);
    infix[-1] = '(';

    while (top != NULL)
    {
        if (infix[i] == ')')
        {
            newnode = new stack1;
            newnode->data = ')';
            newnode->next = top;
            top = newnode;
        }
        else if (infix[i] == '*' || infix[i] == '/' || infix[i] == '+' || infix[i] == '-' || infix[i] == '^')
        {
            while (precedence(top->data) >= precedence(infix[i]))
            {
                p += top->data;
                temp = top;
                top = top->next;
                delete temp;
            }
            newnode = new stack1;
            newnode->data = infix[i];
            newnode->next = top;
            top = newnode;
        }
        else if (infix[i] == '(')
        {
            while (top->data != ')')
            {
                p += top->data;
                temp = top;
                top = top->next;
                delete temp;
            }
            temp = top;
            top = top->next;
            delete temp;
        }
        else
        {
            p += infix[i];
        }

        i--;
    }
     cout<<"=========================================================\n";
    
    reverse(p.begin(), p.end());
    cout << "Prefix expression is: " << p;
     cout<<"\n=========================================================\n";
}
void evalpre(char p[30])
{
    stack2 *newnode, *temp;
    int i = strlen(p) - 1, a, b, c;
    int l = strlen(p);
    p[-1] = '(';
    while (p[i] != '(')
    {
        if (isdigit(p[i]))
        {
            newnode = new stack2;
            newnode->data = p[i] - '0';
            newnode->next = top1;
            top1 = newnode;
        }
        else
        {
            a = top1->data;
            temp = top1;
            top1 = top1->next;
            delete temp;
            b = top1->data;
            temp = top1;
            top1 = top1->next;
            delete temp;

            switch (p[i])
            {
            case '+':
                c = a + b;
                break;
            case '-':
                c = a - b;
                break;
            case '/':
                c = a / b;
                break;
            case '*':
                c = a * b;
                break;
            }
            newnode = new stack2;
            newnode->data = c;
            newnode->next = top1;
            top1 = newnode;
        }
        i--;
    }
     cout<<"=========================================================\n";
    cout << "\n Value of prefix exptession is : " << top1->data;
     cout<<"\n=========================================================\n";
}

int main()
{
    char infix[30], p[30];
    int ch;
    do
    {   cout<<"\nChoose the conversion you want:";
        cout << "\n1. Infix to Prefix";
        cout << "\n2. Evaluation of Prefix";
        cout << "\n3. Exit\n";
        cout<<"=========================================================\n";
        cout << "\n Enter your choice :";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter infix operation ";
            cin >> infix;
            infixprefix(infix);
            break;
        case 2:
            cout << "Enter prefix operation ";
            cin >> p;
            evalpre(p);
            break;
        }
    } while (ch != 3);

    return 0;
}

