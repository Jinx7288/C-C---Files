#include<stdio.h>
#include<stdlib.h>
typedef int ListItem;
typedef struct node *link;
typedef struct node {
    ListItem element;
    link next;
} Node;

link NewNode()
{
    return (link)malloc(sizeof(Node));
}
typedef struct llist *List;
typedef struct llist{
    link first,
        curr,
        last;
} Llist;
List ListInit()
{
    List L = (List)malloc(sizeof *L);
    L->first = 0;
    return L;
}
int ListEmpty(List L)
{
    return L->first == 0;
}
int ListLength(List L)
{
    int len = 0;
    link p = L->first;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}
ListItem ListRetrieve(int k,List L)
{
    if (k<1)
    {
        return 0;
    }
    link p = L->first;
    int i = 1;
    while (i<k && p)
    {
        p = p->next;
        i++;
    }
    return p->element;
}
int ListLocate(ListItem x,List L)
{
    int i = 1;
    link p = L->first;
    while (p && p->element!=x)
    {
        p = p->next;
        i++;
    }
    return p ? i : 0;
}
void ListInsert(int k,ListItem x,List L)
{
    if (k<0) return;
    link p = L->first;
    for (int i = 0; i < k && p; i++)
    {
        p = p->next;
    }
    link y = NewNode();
    y->element = x;
    if(k) {
        y->next = p->next;
        p = p->next;
    } else
    {
        y->next = L->first;
        L->first = y;
    }
}
ListItem ListDelete(int k,List L)
{
    if (k<1 || !L->first) 
    {
        return 0;
    }
    link p = L->first;
    if (k==1)
    {
        L->first = p->next;
    } else
    {
        link q = L->first;
        for (int i = 1; i < k-1 && q; i++)
        {
            q = q->next;
        }
        p = q->next;
        q->next = p->next;
    }
    ListItem x = p->element;
    free(p);
    return x;
}
void ItemShow(ListItem x)
{
    printf("%d \n", x);
}
void PrintList(List L)
{
    for (link p=L->first; p; p=p->next)
    {
        ItemShow(p->element);
    }
}
int main()
{
    List p1 = ListInit();
    printf("%d \t", ListEmpty(p1));
    printf("%d \t", ListLength(p1));
    for (int i = 0; i < 10; i++)
    {
        ListInsert(0, i, p1);
    }
    printf("%d \t", ListEmpty(p1));
    printf("%d \t", ListLength(p1));
    
    printf("%d \t", ListLocate(3, p1));
    printf("%d \n", ListRetrieve(4, p1));

    PrintList(p1);
    ListDelete(4, p1);
    PrintList(p1);
    return 0;
}