#include<iostream>
using namespace std;

#define MAXQSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef char QElemType;
typedef char SElemType;
typedef int Status;

typedef struct {
    QElemType *base;
    int front;
    int rear;
} SqQueue;

Status InitQueue(SqQueue &Q) {
    Q.base=(QElemType*)malloc(sizeof(QElemType)*MAXQSIZE); 
    if (!Q.base)
        exit(OVERFLOW); 
    Q.front=Q.rear=0; 
    return OK;
}

Status EnQueue(SqQueue &Q, QElemType e) {
    if (Q.rear==MAXQSIZE) 
        return ERROR;
    Q.base[Q.rear] = e;   
    Q.rear++; 
    return OK;
}


Status DeQueue(SqQueue &Q, QElemType &e) {
    if (Q.front==Q.rear)
        return ERROR; 
    e = Q.base[Q.front]; 
    Q.front++; 
    return OK;
}


int main() {
    SqQueue Q;
    int n, i; 
    char c;
    InitQueue(Q);
    cin >> n;
    for(i=0;i<n;i++){
        cin >> c;
        EnQueue(Q,c);        
    }

    for(i=0;i<n;i++){
        DeQueue(Q,c);
        cout << c << " ";
    }
    return 0;
}