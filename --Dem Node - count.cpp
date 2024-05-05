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
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
void CreateEmptyTree(TREE &T)
{
    T = NULL;
}
int Insert(TREE &T, int x)
{
    if(T)
    {
        if(T->key == x) return 0;
        if(T->key<x) return Insert(T->pRight, x);
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
        if(x==-1) break;
        else
        {
            Insert(T, x);
        }
    }
}
void CountNode(TREE &T, int &count)
{
    if(T)
    {
        CountNode(T->pLeft, count);
        count++;
        CountNode(T->pRight, count);
    }
}
int main()
{
    TREE T;
    T = NULL;
    CreateTree(T);
    int count=0;
    CountNode(T, count);
    cout<<count;
    return 0;
}
