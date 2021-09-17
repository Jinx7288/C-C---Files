#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

ElementType FindKth( List L, int K );

int main()
{
    int N, K;
    ElementType X;
    List L = Read();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &K);
        X = FindKth(L, K);
        if ( X!= ERROR )
            printf("%d ", X);
        else
            printf("NA ");
    }
    return 0;
}

ElementType FindKth( List L, int K ) {
     while(--K)
      {
          if(!L)return ERROR;
          L = L->Next;
      }
      if(L)return L->Data;
     return ERROR;
}

ElementType FindKth( List L, int K ) {
    if (K<0 || L==NULL)
    {
        return ERROR;
    }
    PtrToLNode l = L;
    for (int i = 0; i < K; i++)
    {
        if (l->Next)
        {
            l = l->Next;      
        } else
        {
            return ERROR;
        }
    }
    if (l)
    {
           return l->Data;
    } else
    {
        return ERROR;
    }
    
}