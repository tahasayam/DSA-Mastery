#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define MAX 100

int top = -1;
char stack[MAX];
char infix[MAX];
char postfix[MAX];

int IsFull()
{
    if (top == MAX - 1)
    {
        return 1;
    }
    return 0;
}

int IsEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

void Push(int data)
{
    if (IsFull())
    {
        printf("Stack overflow\n");
        return;
    }
    top++;
    stack[top] = data;
}

int Pop()
{
    if (IsEmpty())
    {
        printf("Stack is Empty");
        return 0;
    }
    int value = stack[top];
    top--;
    return value;
}

// function to check precedence
int Precedence(char symbol)
{
    switch (symbol)
    {
    // Higher value means greater precedence
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}
// function to convert infix to postfix
void inToPost()
{
    char symbol, next;
    int j = 0;
    int len = strlen(infix);
    for (int i = 0; i < len; i++)
    {
        symbol = infix[i];
        switch (symbol)
        {
        case '(':
            Push(symbol);
            break;
        case ')':
            next = Pop();
            while (next != '(')
            {
                postfix[j++] = next;
                next = Pop();
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
            while (!IsEmpty() && Precedence(stack[top]) >= Precedence(symbol))
            {
                postfix[j++] = Pop();
            }
            Push(symbol);
            break;

        default:
            postfix[j++] = symbol;
        }
    }
    while (!IsEmpty())
    {
        postfix[j++] = Pop();
        postfix[j] = '\0';
    }
}

// function to evalate postfix expression
int evalpostfix()
{
    int len = strlen(postfix);
    int a, b;
    for (int i = 0; i < len; i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            Push(postfix[i] - '0'); // for evaluation we have to stroe integrs in stack so we can dot hid like '7' - '0'  => '7'=55 and '0'=48 so 55-48=7 now 7 is an integer;

            // ASCII code of '0' is 48
            // ASCII code of '1' is 49
            // ASCII code of '2' is 50
            // ASCII code of '3' is 51
            // ASCII code of '4' is 52
            // ASCII code of '5' is 53
            // ASCII code of '6' is 54
            // ASCII code of '7' is 55
            // ASCII code of '8' is 56
            // ASCII code of '9' is 57
        }
        else
        {
            a = Pop();
            b = Pop();

            switch (postfix[i])
            {
            case '+':
                Push(a + b);
                break;
            case '-':
                Push(b - a);
                break;

            case '*':
                Push(b * a);
                break;
            case '/':
                Push(b / a);
                break;
            case '^':
                Push(pow(b, a));
                break;
            }
        }
    }
    return Pop();
}

main()
{
    int result;
    printf("Enter the infix expression: ");
    gets(infix);

    inToPost();
    result = evalpostfix();
    printf("Postfix expression: %s\n", postfix);
    printf("Result: %d\n", result);
}