#include<iostream>
using namespace std;
struct TNODE
{
    int key;
    TNODE* pLeft;
    TNODE* pRight;
};
typedef TNODE* TREE;
TNODE* CreateTNode(int x)
{
    TNODE* p = new TNODE;
    p -> key = x;
    p -> pLeft = NULL;
    p -> pRight = NULL;
    return p;
}
int Insert(TREE &T, int x)
{
    if(T)
    {
        if(T->key == x) return 0;
        if(T->key < x)
        {
            return Insert(T->pRight, x);
        }
        else return Insert(T->pLeft, x);
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
void CountLeaf(TREE T, int &count)
{
    if(T)
    {
         if(T->pLeft==NULL&&T->pRight==NULL) count++;
         else{
        CountLeaf(T->pLeft, count);
        CountLeaf(T->pRight, count);}

    }
}
int main()
{
    TREE T;
    T = NULL;
    CreateTree(T);
    int count = 0;
    CountLeaf(T, count);
    cout<<count;
    return 0;
}
