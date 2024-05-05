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
    TNODE* p;
    p = new TNODE;
    p -> key = x;
    p -> pLeft = NULL;
    p -> pRight = NULL;
    return p;
}
int Insert(TREE& T, int x)
{
    if(T)
    {
        if(T -> key == x) return 0;
        else
        {
            if(T -> key > x) return Insert(T->pLeft, x);
            return Insert(T->pRight, x);
        }
    }
    T = CreateTNode(x);
    return 1;
}
void CreateTree(TREE& T)
{
    int  x;
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
bool searchNode(TREE T, int x)
{
    if(T)
    {
        if(T->key == x) return true;
        else
        {
            if(T->key<x) return searchNode(T->pRight, x);
            return searchNode(T->pLeft, x);
        }
    }
    return false;
}
int main()
{
    TREE T;
    T = NULL;
    CreateTree(T);
    int x;
    cin>>x;
    if(searchNode(T, x)) cout<<"true";
    else cout<<"false";
    return 0;
}
