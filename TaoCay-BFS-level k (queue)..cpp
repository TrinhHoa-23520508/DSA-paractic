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
int Insert(TREE &T, int x)
{
    if(T)
    {
        if(T->key==x) return 0;
        if(T->key>x) return Insert(T->pLeft, x);
        return Insert(T->pRight, x);

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
void ThayThe(TNODE* &p, TNODE* &T)
{
    if(T->pLeft!=NULL)
    {
        ThayThe(p, T->pLeft);
    }
    p->key = T->key;
    p = T;
    T = T->pRight;
}
void DeleteNode(TREE &T, int x)
{
    if(T)
    {
        if(T->key>x) DeleteNode(T->pLeft, x);
        else
        {
            if(T->key<x) DeleteNode(T->pRight, x);
            else
            {
                TNODE* temp = T;
                if(T->pLeft==NULL) T = T->pRight;
                else
                {
                    if(T->pRight==NULL) T = T->pLeft;
                    else
                    {
                        ThayThe(temp, T->pRight);
                    }
                }
                delete temp;
            }
        }
    }


}
void NLR(TREE T)
{
    if(T)
    {
        cout<<T->key<<" ";
        NLR(T->pLeft);
        NLR(T->pRight);
    }
}
void PrintTree(TREE T)
{
    if(T==NULL) cout<<"Empty Tree.";
    else
    {
        NLR(T);
    }
}
int main()
{
    TREE T;
    T = NULL;
    CreateTree(T);
    int x;
    cin>>x;
    DeleteNode(T, x);
    PrintTree(T);
    return 0;
}
