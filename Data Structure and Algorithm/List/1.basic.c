#include<stdio.h>
#include<stdlib.h>
typedef int ListItem;

typedef struct alist *List;
typedef struct alist
{
    int n,
        curr;
    int maxsize;
    ListItem *table;
} Alist;
void ItemShow(ListItem x)
{
    printf("%d \n", x);
}
List ListInit(int size)
{
    List L = (List)malloc(sizeof *L);
    L->table = (ListItem *)malloc(size * sizeof(ListItem));
    L->maxsize = size;
    L->n = 0;
    return L;
}
int ListEmpty(List L) 
{
    return L->n == 0;
}
int ListLength(List L)
{
    return L->n;
}
int ListLocate(ListItem x,List L)
{
    for (int i = 0; i < L->n; i++)
    {
        if (L->table[i]==x)
        {
            return ++i;
        }
    }
    return 0;
}
ListItem ListRetrieve(int k,List L)
{
    if (k<1 || k>L->n) 
    {
        /* code */
        return 0;
    }
    return L->table[k - 1];
}
void ListInsert(int k,ListItem x,List L)
{
    if (k<0 || k>L->n)
    {
        return;
    }
    for (int i = L->n-1; i>=k; i++)
    {
        L->table[i + 1] = L->table[i];
    }
    L->table[k] = x;
    L->n++;
}
ListItem ListDelete(int k,List L)
{
    if (k<1 || k>L->n)
    {
         return 0;
    }
    ListItem x = L->table[k - 1];
    for (int i = k; i < L->n; i++)
    {
        L->table[i - 1] = L->table[i];
    }
    L->n--;
    return x;
}
void PrintList(List L)
{
    for (int i = 0; i < L->n; i++)
    {
        ItemShow(L->table[i]);
    }
}
void ListFree(List L)
{
    free(L->table);
    free(L);
}
int main()
{
    List p1 = ListInit(20);
    printf("%d \t", ListEmpty(p1));
    printf("%d \t", ListLength(p1));
    for (int i = 0; i < 10; i++)
    {
        ListInsert(i, i, p1);
    }
    printf("%d \t", ListEmpty(p1));
    printf("%d \t", ListLength(p1));
    
    printf("%d \t", ListLocate(3, p1));
    printf("%d \n", ListRetrieve(4, p1));

    PrintList(p1);
    ListDelete(4, p1);
    PrintList(p1);
    ListFree(p1);
    return 0;
}