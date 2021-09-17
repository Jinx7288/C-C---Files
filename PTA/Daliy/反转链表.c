#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

List Reverse( List L )
{
    if (L==NULL || L->Next==NULL)
    {
        return L;
    }
    else
    {
        PtrToNode beg = NULL;
        PtrToNode mid = L;
        PtrToNode end = L->Next;
        while (1)
        {
            mid->Next = beg;
            if (end==NULL)
            {
                break;
            }
            beg = mid;
            mid = end;
            end = end->Next;
        }
        L = mid;
        return L;
    }
}
List Reverse_2(List L)
{
    PtrToNode temp;
    PtrToNode new_head;
    if (L==NULL || L->Next==NULL)
    {
        return L;
    } else
    {
        temp = L;
        L = L->Next;
        temp->Next = new_head;
        new_head = temp;
        return new_head;
    }
    
    
}