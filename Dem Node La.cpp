#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;
TNODE* CreateTNode(int x)
{
    TNODE *p = new TNODE;
    p -> key = x;
    p -> pLeft = NULL;
    p -> pRight = NULL;
    return p;
}
int Insert(TREE &T, int x)
{
    if(T)
    {
        if(T->key==x) return 0;
        if(T->key<x)
        {
            return Insert(T->pRight, x);
        }
        return Insert(T->pLeft, x);
    }
    T = CreateTNode(x);
    return 1;
}
void CreateTree(TREE &T)
{
    int x;
    while(1)
    {
        cin>>x;
        if(x==-1) return;
        else
        {
            Insert(T, x);
        }
    }
}
int CountLeaf(TREE T)
{
    if(T)
    {
        if(T->pLeft==NULL&&T->pRight==NULL)
            return 1;
        else
        {
            return CountLeaf(T->pLeft)+CountLeaf(T->pRight);
        }
    }
    return 0;
}
int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	cout << CountLeaf(T);
	return 0;
}


