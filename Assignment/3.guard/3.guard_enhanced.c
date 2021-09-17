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
    int n,m,temp;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        ListInsert(0, temp, p1);
    }
    // PrintList(p1);
    int sum = 0;
    int max=0;
    int count = 0;
    for (link p = p1->first; p;p=p->next)
    {
        count = 0;
        sum = 0;
        link p2 = p;
        // printf("%d", p2->element);
        for (int i = m; i >0;i--)
        {
            // printf("%d \n", p2->element * i);
            sum += (p2->element)*i;
            p2=p2->next;
            if (p2)
            {
               count++;
            }
        }
        // printf("%d \n",sum);
        if (sum>=max && count==m)
        {   
            max=sum;
        }
        
    }
    printf("%d", max);
    return 0;
}