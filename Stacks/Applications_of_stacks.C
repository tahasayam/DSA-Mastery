#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 100

int top = -1;
char stack[MAX];

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

bool char_match(char a, char b)
{
    if (a == '(' && b == ')') return true;
    if (a == '{' && b == '}') return true;
    if (a == '[' && b == ']') return true;
    return false;
}

// To check balance of parentheses
int CheckBalance(char *S)
{
    int len = strlen(S);
    char poped;
    for (int i = 0; i < len; i++)
    {
        if (S[i] == '[' || S[i] == '{' || S[i] == '(')
        {
            Push(S[i]);
        }
        if (S[i] == ']' || S[i] == '}' || S[i] == ')')
        {
            if (IsEmpty())
            {
                printf("right brackets ar more then Left SO Its  -------------- Invalid Expression-------------\n");
                return 0;
            }
            else
            {
                poped = Pop();
                if (!char_match(poped, S[i]))
                {
                    printf("right not equal  -------------- Invalid Expression-------------\n");
                    return 0;
                }
            }
        }
    }
    if (IsEmpty())
    {
        printf("Brackets are Well Balanced\n");
        return 1;
    }
    else
    {
        printf("Left brackets are more then right brackets SO Its  -------------- Invalid Expression-------------\n");
        return 0;
    }
}

main()
{
    // char Exp[MAX];
    // printf("Enter the expression: ");
    // gets(Exp);
    // Better to use fgets instead of gets, as gets is unsafe and can lead to buffer overflow
    char Exp[MAX];
    printf("Enter the expression: ");
    fgets(Exp, MAX, stdin);

    int balance;
    balance = CheckBalance(Exp);
    if (balance == 1)
    {
        printf("The expression is balanced.\n");
    }
    else
    {
        printf("The expression is not balanced.\n");
    }
}