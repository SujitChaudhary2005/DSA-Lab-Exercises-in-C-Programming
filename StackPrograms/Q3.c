// Program to evaluate a postfix expression by using a stack.
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

int vstack[100];
int tos = -1;

// Push a value onto the stack
void push(int val){
    vstack[++tos] = val;
}

// Pop a value from the stack
int pop(){
    return vstack[tos--];
}

// Peek the top value of the stack
int peek(){
    return vstack[tos];
}

int main(){
    int i, len, op1, op2, value[100];
    char postfix[100], ch;

    // Get postfix expression from user
    printf("Enter the postfix expression: ");
    gets(postfix); // Note: gets() is unsafe, consider using fgets() instead

    len = strlen(postfix);

    // Process each character in the postfix expression
    for (i = 0; i < len; i++){
        if(isalpha(postfix[i])){ // If operand
            printf("Enter the value of %c: ", postfix[i]);
            scanf("%d", &value[i]);
            push(value[i]);
        }
        else{ // If operator
            op2 = pop();
            op1 = pop();
            switch (postfix[i]){
            case '+':
                push(op1 + op2);
                break;
            case '-':
                push(op1 - op2);
                break;
            case '*':
                push(op1 * op2);
                break;
            case '/':
                push(op1 / op2);
                break;
            case '^':
            case '$':
                push(pow(op1, op2));
                break;
            case '%':
                push(op1 % op2);
                break;
            default:
                break;
            }
        }
    }

    // Print the result
    printf("The result of the postfix expression is: %d\n", pop());

    return 0;
}