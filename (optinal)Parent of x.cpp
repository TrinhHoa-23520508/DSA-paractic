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
void CreateEmptyTree(TREE &T)
{
    T = NULL;
}
int Insert(TREE &T, TNODE* p)
{
    if(T)
    {
        if(T->key == p->key) return 0;
        if(T->key > p->key) return  Insert(T->pLeft, p);
        return Insert(T->pRight, p);
    }
    T = p;
    return 1;
}
void  CreateTree(TREE &T)
{
    int x;
    while(1)
    {
        cin>>x;
        if(x==-1) break;
        else
        {
            Insert(T, CreateTNode(x));
        }
    }
}
void FindParent(TREE T, int x)
{
    if(T==NULL) cout<<"Empty Tree.";
    else
    {
        TNODE* parent ;
        if(T->key == x) cout<<x<<" has no parent.";
        else
        {
            while(T&&T->key!=x)
            {
                parent = T;
                if(T->key>x)
                {
                    T = T->pLeft;
                }
                else T = T->pRight;
            }
            if(T==NULL) cout<<"Not found "<<x<<".";
            else
            {
                cout<<parent->key<<" is parent of "<<x<<".";
            }
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
    FindParent(T, x);
    return 0;
}
