#include <iostream>
#include <string>
using namespace std;

char Stack[100];
int top = -1;

void push(char x) {
    top++;
    Stack[top] = x;
}

char pop() {
    char x = Stack[top];
    top--;
    return x;
}

int priority(char x) {
    if (x == '^')
        return 3;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    else
        return 0;
}

int main() {
    string infix;

    cout << "Enter infix expression";
    cin >> infix;

    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {

        char ch = infix[i];


        if ((ch >= '0' && ch <= '9') ||
            (ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z')) {

            postfix = postfix + ch;
        }


        else if (ch == '(') {
            push(ch);
        }


        else if (ch == ')') {

            while (Stack[top] != '(') {
                postfix = postfix + pop();
            }

            pop();
        }


        else {
            while (top != -1 && priority(Stack[top]) >= priority(ch)) {

                postfix = postfix + pop();
            }

            push(ch);
        }
    }


    while (top != -1) {
        postfix = postfix + pop();
    }

    cout << "Postfix expression is " << postfix << endl;

    return 0;
}
