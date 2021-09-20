#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char StackItem;
typedef int StackItemValue;
typedef double CalItem;
typedef struct snode *slink;
typedef struct snode{
    StackItem element[2];
    StackItemValue value;
    CalItem calvalue;
    slink next;
} StackNode;
typedef struct lstack *Stack;
typedef struct lstack
{
    slink top;
}Lstack;
void StackShow(StackItem x[])
{
    printf("%s", x);
}
slink NewStackNode() {
    return (slink)malloc(sizeof(StackNode));
}
Stack StackInit()
{
    Stack S = (Stack)malloc(sizeof *S);
    S->top = 0;
    return S;
}
int StackEmpty(Stack S) {
    return S->top == 0;
}
// int StackFull(Stack S) {    
// }
StackItemValue StackTop(Stack S) {
    if (StackEmpty(S))
        return 0;
    return S->top->value;
}
void Push(StackItem x[],StackItemValue v,Stack S) {
    slink p = NewStackNode();
    strcpy(p->element, x);
    // p->element = x;
    p->value = v;
    p->calvalue = 0.0;
    p->next = S->top;
    S->top = p;
}
void Push2(CalItem cit,Stack S) {
    slink p = NewStackNode();
    p->value = 0;
    p->calvalue = cit;
    p->next = S->top;
    S->top = p;
}
char *Pop(Stack S) {
    if(StackEmpty(S))
        return 0;
    slink p = S->top;
    S->top = p->next;
    return p->element;
}
CalItem Pop2(Stack S)
{
    if(StackEmpty(S))
        return 0;
    slink p = S->top;
    S->top = p->next;
    return p->calvalue;
}
int dig2str(char *s)
{
    int i, j, n, sum = 0;
    n = strlen(s);
    for ( i = 0,j=10; i < n; i++)
    {
        sum = sum * j + *s - 48;
        s++;
    }
    return sum;
}
void StackFree(Stack S) { free(S); }
int main() {
    char inlstr[220]="";
    char laterstr[220]="";
    Stack sk = StackInit();
    // Push("#",-1, sk);
    gets(inlstr);
    int n = strlen(inlstr);
    for (int i = 0; i < n; i++)
    {
        if (inlstr[i]==' ')
        {
            inlstr[i] = '_';
        }
    }
    // printf("%s", inlstr);
    char *delim = "_";
    char *p;
    char firststr[20]="";
    char temp2[10]="";
    char cache[20] = "";
    p = strtok(inlstr, delim);
    strcpy(firststr,p);
    strcat(firststr, "_");
    strcat(laterstr, firststr);
    // printf("%s\n", firststr);
    while((p = strtok(NULL, delim)))
    {
        strcpy(cache, p);
        // printf("%s\n", p);
        if (strcmp(cache, "+") != 0 && strcmp(cache, "-") != 0 && strcmp(cache, "*") != 0 && strcmp(cache, "/") != 0)
        {
            strcat(cache, "_");
            strcat(laterstr, cache);
        }
        // printf("%s", cache);
        if (strcmp(cache,"+")==0 || strcmp(cache,"-")==0)
        {
            if (!StackEmpty(sk) && StackTop(sk)==2)
            {
                strcpy(temp2, Pop(sk));
                strcat(temp2, "_");
                strcat(laterstr, temp2);
            }
            Push(cache, 1, sk);
        }
        if (strcmp(cache,"*")==0 || strcmp(cache,"/")==0)
        {
            if (!StackEmpty(sk) && StackTop(sk)==2)
            {
                strcpy(temp2, Pop(sk));
                strcat(temp2, "_");
                strcat(laterstr, temp2);
            }
            Push(cache, 2, sk);
        }
    }
    char temp[2];
    while (!StackEmpty(sk))
    {
        char *d = Pop(sk);
        strcpy(temp,d);
        strcat(temp,"_");
        // strcat(instr, Pop(sk));
        strcat(laterstr, temp);
    }
    StackFree(sk);
    // printf("%s\n", laterstr);
    p = strtok(laterstr, delim);
    Stack cal = StackInit();
    char *ccc = p;
    int dd = dig2str(ccc);
    Push2(dd, cal);
    double dca1 = 0.0;
    double dca2 = 0.0;
    // strcpy(cache, NULL);
    while((p = strtok(NULL, delim)))
    {
        strcpy(cache, p);
        if (strcmp(cache, "+") != 0 && strcmp(cache, "-") != 0 && strcmp(cache, "*") != 0 && strcmp(cache, "/") != 0)
        {
            Push2(dig2str(cache), cal);
        }
            else
        {
            if (strcmp(cache,"+")==0)
            {
                dca1 = Pop2(cal);
                dca2 = Pop2(cal);
                Push2(dca1 + dca2,cal);
            }
            if (strcmp(cache,"-")==0)
            {
                dca1 = Pop2(cal);
                dca2 = Pop2(cal);
                Push2(dca1 - dca2,cal);
            }
            if (strcmp(cache,"*")==0)
            {
                dca1 = Pop2(cal);
                dca2 = Pop2(cal);
                Push2(dca1 * dca2,cal);
            }
            if (strcmp(cache,"/")==0)
            { 
                dca1 = Pop2(cal);
                dca2 = Pop2(cal);
                Push2(dca2 / dca1,cal);
            }
        }
    }
    printf("%.2f", Pop2(cal));
    return 0;
}