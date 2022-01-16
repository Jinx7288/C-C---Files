#include<bits/stdc++.h>
using namespace std;
typedef struct btnode *btlink;
struct btnode{
	int element;	
	btlink left;
	btlink right;
}Btnode;
btlink CreateTree(int n)
{
    // printf("%d\n", n);
    btlink root = (btlink)malloc(sizeof(root));
    root->element = n;
    root->left = NULL;
    root->right = NULL;
    if (n-1>0)
    {
        root->left = CreateTree(n - 1);
    }
    if (n-1>0)
    {
        root->right = CreateTree(n - 1);
    }
    return root;
}
void PreOrder(btlink t)
{
    if (t)
    {
        // printf("%d\n", t->element);
        PreOrder(t->left);
        printf("%d\n", t->element);
        PreOrder(t->right);
        // printf("%d\n", t->element);
    }
}
int main()
{
    btlink t = CreateTree(3);
    PreOrder(t);
}