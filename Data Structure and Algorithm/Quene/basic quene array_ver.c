#include<stdio.h>
#include<stdlib.h>
typedef int QItem;
typedef struct aqueue *Queue;
typedef struct aqueue{
    int maxsize;
    int front;
    int rear;
    QItem *queue;
} Aquene;
Queue QueueInit(int size)
{
    Queue Q = (Queue)malloc(sizeof *Q);
    Q->queue = (QItem *)malloc(size * sizeof(QItem));
    Q->maxsize = size;
    Q->front = Q->rear = 0;
    return Q;
}
int QueueEmpty(Queue Q)
{
    return Q->front == Q->rear;
}
int QueueFull(Queue Q)
{
    return (((Q->rear + 1) % Q->maxsize == Q->front) ? 1 : 0);
}
QItem QueueFirst(Queue Q)
{
    if(QueueEmpty(Q))
        return 0;
    return Q->queue[(Q->front + 1) % Q->maxsize];
}
QItem QueueLast(Queue Q)
{
    if(QueueEmpty(Q))
        return 0;
    return Q->queue[Q->rear];
}
void EnterQueue(QItem x,Queue Q)
{
    if (QueueFull(Q)) return;
    Q->rear = (Q->rear + 1) % Q->maxsize;
    Q->queue[Q->rear] = x;
}
QItem DeleteQueue(Queue Q)
{
    if (QueueEmpty(Q))
    {
        return 0;
    }
    Q->front = (Q->front + 1) % Q->maxsize;
    return Q->queue[Q->front];
}
int main()
{
    // ! 因为约定了size-1时为满，所以size为10，存9个数
    Queue qq = QueueInit(10);
    printf("%d\n", QueueEmpty(qq));
    for (int i = 0; i < 12; i++)
    {
        EnterQueue(i, qq);
    }
    printf("%d\n", QueueFirst(qq));
    printf("%d\n", QueueLast(qq));
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", DeleteQueue(qq));
        // printf("%d\n", QueueEmpty(qq));
    }
    // printf("%d\n", QueueEmpty(qq));
    // printf("%d\n", QueueFirst(qq));
    // printf("%d\n", QueueLast(qq));
    return 0;
}