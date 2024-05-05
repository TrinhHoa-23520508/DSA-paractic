#include<iostream>
using namespace std;
struct TNODE
{
    int key;
    TNODE* pLeft;
    TNODE* pRight;
};
typedef TNODE* TREE;
void CreateEmptyTree(TREE &T)
{
    T = NULL;
}
TNODE* CreatTNode(int x)
{
    TNODE* p = new TNODE;
    p -> key = x;
    p -> pLeft = NULL;
    p -> pRight = NULL;
    return p;
}

void CreateTree(TREE &T)
{
    int x;
    while(1)
    {
        cin>>x;
        if(x==-1) return ;
        else
        {
            Insert(T, CreateTNode(x));
        }
    }
}
void FindSiblings(TREE T, int x)
{
    if(T==NULL)
    {
        cout<<"Empty Tree.";
    }
    else
    {
        TNODE* Parent = T;
        if(Parent->key == x) cout<<x<<" is Root.";
        else
        {
            while(T!=NULL&&T->key!=x)
            {
                if(T->key<x)
                {
                    Parent = T;
                    T = T->pRight;
                }
                else
                {
                    Parent = T;
                    T = T->pLeft;
                }
            }
            if(T==NULL) cout<<"Not found "<<x<<".";
            else if(Parent->pLeft==NULL||Parent->pRight==NULL) cout<<x<<" has no siblings.";
            else cout<<Parent->pLeft->key<<" and "<<Parent->pRight->key<<" are siblings.";
        }
    }
}
int main()
{
    TREE T;
    T = NULL;
    CreateTree(T);
    int x;
    cin>>x;
    FindSiblings(T, x);
    return 0;
}
