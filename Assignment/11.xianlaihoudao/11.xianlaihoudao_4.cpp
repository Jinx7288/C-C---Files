#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
using namespace std;
typedef int TreeItem;
typedef TreeItem* Treeaddr;
void TreeItemShow(TreeItem x)
{
	printf("%d \n",x);
}
typedef struct btnode *btlink;
struct btnode{
	TreeItem element;
	btlink left;
	btlink right;
}Btnode;
btlink NewNode()
{
	return (btlink)malloc(sizeof(sizeof(Btnode)));
}
typedef struct binarytree *BinaryTree;
typedef struct binarytree{
	btlink root;
}Btree;
BinaryTree BinaryInit()
{
	BinaryTree T= (BinaryTree)malloc(sizeof *T);
	T->root=0;
	return T;
}
int BinaryEmpty(BinaryTree T)
{
	return T->root==0;
}
TreeItem Root(BinaryTree T)
{
	if(BinaryEmpty(T)) return 0;
	return T->root->element;
}
void MakeTree(TreeItem x,BinaryTree T,BinaryTree L,BinaryTree R)
{
	T->root=NewNode();
	T->root->element=x;
	T->root->left=L->root;
	T->root->right=R->root;
	L->root=R->root=0; // ? 这里是啥意思
}
TreeItem BreakTree(BinaryTree T,BinaryTree L,BinaryTree R)
{
	if(!T->root) return 0;
	TreeItem x = T->root->element;
	L->root=T->root->left;
	R->root=T->root->right;
	T->root=0;
}
void PreOrder(void(*visit)(btlink u),btlink t)
{
	if(t)
	{
		(*visit)(t);
		PreOrder(visit,t->left);
		PreOrder(visit,t->right);
	}
}
void InOrder(void(*visit)(btlink u),btlink t)
{
	if(t)
	{
		InOrder(visit,t->left);
		(*visit)(t);
		InOrder(visit,t->right);
	}
}void PostOrder(void(*visit)(btlink u),btlink t)
{
	if(t)
	{
		PostOrder(visit,t->left);
		PostOrder(visit,t->right);
		(*visit)(t);
	}
}
void LevelOrder(void(*visit)(btlink u),btlink t)
{
	queue<btlink> qbts;
	qbts.push(t);
	while(!qbts.empty())
	{
		(*visit)(t=qbts.front());
		qbts.pop();
		if(t->left) qbts.push(t->left);
		if(t->right) qbts.push(t->right);
	}
}
void visit(btlink u)
{
	printf("%d \n",u->element);
}
void outnode(btlink t)
{
	TreeItemShow(t->element);
}
void PreOut(BinaryTree T)
{
	PreOrder(outnode,T->root);
}
void InOut(BinaryTree T)
{
	InOrder(outnode,T->root);
}void PostOut(BinaryTree T)
{
	PostOrder(outnode,T->root);
}
void LevelOut(BinaryTree T)
{
	LevelOrder(outnode,T->root);
}
int Height(btlink t)
{
	int hl,hr;
	if(!t) return -1;
	hl=Height(t->left);
	hr = Height(t->right);
	if(hl>hr) return ++hl;
	else return ++hr;
}
int main()
{
    
}
