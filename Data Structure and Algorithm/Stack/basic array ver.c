#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define eq(A,B) (A==B)
typedef int StackItem;
typedef StackItem *addr;
typedef struct astack *Stack;
typedef struct astack 
{
    int top,
        maxtop;
    StackItem *data;
}Astack;
void StackShow(StackItem x)
{
    printf("%d", x);
}
Stack StackInit(int size)
{
    Stack S = (Stack)malloc(sizeof *S);
    S->data = (StackItem *)malloc(size * sizeof(StackItem));
    S->maxtop = size;
    S->top = -1;
    return S;
}
int StackEmpty(Stack S) {
    return S->top < 0;
}
int StackFull(Stack S) {
    return S->top>= S->maxtop;
}
StackItem StackTop(Stack S) {
    if (StackEmpty(S))
        return 0;
    return S->data[S->top];
}
void Push(StackItem x,Stack S) {
    if(StackFull(S))
        return;
    S->data[++S->top] = x;
}
StackItem Pop(Stack S) {
    if(StackEmpty(S))
        return 0;
    return S->data[S->top--];
}
void StackFree(Stack S) {
    free(S->data);
    free(S);
}
int main() {
    char str[100];
    scanf("%s", str);
    Stack ss = StackInit(51);
    int n = strlen(str);
    for (int i = 0; i <= n; i++)
    {
        if (str[i-1]=='(') 
        {
            Push(i, ss);
        } else if (str[i-1]==')')
        {
            if(StackEmpty(ss))
                printf("位置%d 处的右括号不匹配\n", i);
                else
                    printf("%d %d \n", Pop(ss), i);
        }
    }

    while (!StackEmpty(ss))
    {
        printf("位置%d 处的左括号不匹配\n",Pop(ss));
    }
}