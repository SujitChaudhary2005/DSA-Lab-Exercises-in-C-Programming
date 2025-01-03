// Program to convert an infix expression to postfix using the stack data structure.
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

// Function to determine the precedence of operators
int precedence(char c){
    if (c == '^' || c == '$')
        return 4;
    else if (c == '*' || c == '/')
        return 3;
    else if (c == '+' || c == '-')
        return 2;
    else
        return 1;
}

int main(){
    int otos = -1, ptos = -1, Length1, Length2;
    char infix[100], postfix[100], opstack[100];

    printf("Enter a valid infix: ");
    gets(infix); // Read the infix expression

    Length2 = strlen(infix);
    Length1 = Length2;

    for (int i = 0; i <= Length2 - 1; i++) {
        if (infix[i] == '(') {
            opstack[++otos] = infix[i]; // Push '(' to stack
            Length1++;
        }
        else if (isalpha(infix[i])) {
            postfix[++ptos] = infix[i]; // Add operand to postfix expression
        }
        else if (infix[i] == ')') {
            Length1++;
            // Pop from stack to postfix until '(' is found
            while (opstack[otos] != '(') {
                postfix[++ptos] = opstack[otos];
                otos--;
            }
            otos--; // Pop the '('
        }
        else {
            // Pop from stack to postfix while top of stack has higher or equal precedence
            while (otos != -1 && precedence(opstack[otos]) >= precedence(infix[i])) {
                postfix[++ptos] = opstack[otos--];
            }
            opstack[++otos] = infix[i]; // Push current operator to stack
        }
    }

    // Pop all remaining operators from stack to postfix
    while (otos != -1) {
        postfix[++ptos] = opstack[otos--];
    }

    // Print the postfix expression
    for (int i = 0; i <= ptos; i++) {
        printf("%c", postfix[i]);
    }

    return 0;
}