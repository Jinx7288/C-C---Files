#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef struct SNode {
    int data;
    struct SNode *next;
} SNode, *LinkStack;

Status InitStack(LinkStack &S) {
    S = NULL;
    return OK;
}
bool StackEmpty(LinkStack S) {
    if (!S)
        return true;
    return false;
}
Status Push(LinkStack &S, int e) {
    LinkStack p;
    p = new SNode;
    if (!p) {
        return OVERFLOW;
    }
    p->data = e;
    p->next = S;
    S = p;
    return OK;
}
Status Pop(LinkStack &S, int &e) {
    LinkStack p;
    if (!S)
        return ERROR;
    e = S->data;
    p = S;
    S = S->next;
    delete p;
    return OK;
}

void conversion(int N) {
    int e;
    LinkStack S;
    InitStack(S); 
    while (N) 
    {
        Push(S, N % 8);
        N = N / 8; 
    }
    while (!StackEmpty(S))
    {
        Pop(S, e);
        cout << e; 
    }
}
int main() {
    int n;
    cin >> n;
    conversion(n);
    return 0;
}