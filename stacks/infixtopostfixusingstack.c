#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int push(char stack[], int top, char c);
char pop(char stack[], int *top);
int precedence(char c);
int isOperator(char c);

int main()
{
    char stack[100];
    int top = -1;
    int j = 0;
    char infix[100], postfix[100];

    printf("Enter the infix expression: ");
    if (scanf("%99s", infix) != 1) {
        fprintf(stderr, "Input error\n");
        return 1;
    }

    int l = strlen(infix);
    infix[l] = ')';
    infix[l + 1] = '\0';
    stack[++top] = '(';

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (ch == '(') {
            top = push(stack, top, ch);
        } else if (isOperator(ch)) {
            while (top >= 0 && stack[top] != '(' &&
                   ((ch == '^' && precedence(stack[top]) > precedence(ch)) ||
                    (ch != '^' && precedence(stack[top]) >= precedence(ch)))) {
                postfix[j++] = pop(stack, &top);
            }
            top = push(stack, top, ch);
        } else if (ch == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = pop(stack, &top);
            }
            if (top >= 0 && stack[top] == '(') {
                top--;
            }
        } else {
            postfix[j++] = ch;
        }
    }

    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
    return 0;
}

int push(char stack[], int top, char c)
{
    stack[++top] = c;
    return top;
}

char pop(char stack[], int *top)
{
    return stack[(*top)--];
}

int precedence(char c)
{
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}
