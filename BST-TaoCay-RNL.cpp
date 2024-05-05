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
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
void CreateEmptyTree(TREE &T)
{
    T = NULL;
}
/*int Insert(TREE &T, int x)//su dung de quy
{
    if(T)
    {
        if(T->key<x) return Insert(T->pRight, x);
        if(T->key>x) return Insert(T->pLeft, x);
        else return 0;
    }
    T = CreateTNode(x);
    return 1;

}*/
int Insert(TREE &T, int x)//khong su dung de quy
{
    if(T==NULL) T = CreateTNode(x);
    else
    {
        TREE Root = T;
        while(Root)
        {
            if(Root->key==x) return 0;
            if(Root->key>x)
            {
                if(Root->pLeft == NULL) Root->pLeft = CreateTNode(x);
                else Root = Root->pLeft;
            }
            else
            {
                if(Root->pRight == NULL) Root->pRight = CreateTNode(x);
                else Root = Root->pRight;
            }
        }

    }
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
void Print_RNL_Tree(TREE T)
{
    if(T)
    {
        Print_RNL_Tree(T->pRight);
        cout<<T->key<<" ";
        Print_RNL_Tree(T->pLeft);

    }
}
void PrintTree(TREE T)//RNL
{
    if(T==NULL) cout<<"Empty Tree.";
    else
    {
        Print_RNL_Tree(T);
    }

}

int main()
{
    TREE T;//hay: TNODE* T
    T = NULL;//khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);
    PrintTree(T);
    return 0;
}

