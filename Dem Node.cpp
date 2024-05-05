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
TNODE* CreateTNode(int x)
{
    TNODE *p = new TNODE;
    p -> key = x;
    p -> pLeft = NULL;
    p -> pRight = NULL;
    return p;
}
int Insert(TREE &T, TNODE *p)
{
    if(T)
    {
        if(T->key == p->key) return 0;
        if(T->key > p->key)
            return Insert(T->pLeft, p);
        return Insert(T->pRight, p);
    }
    T = p;
    return 1;

}
void CreateTree(TREE &T)
{
    int x;
    do
    {
        cin>>x;
        if(x == -1 ) break;
        Insert(T, CreateTNode(x));
    }while(true);
}
void Browse_RNL(TREE T, int &count )
{
    if(T)
    {
        Browse_RNL(T->pRight, count);
        count++;
        Browse_RNL(T->pLeft, count);
    }
}
int CountNode(TREE T)
{
    int count = 0;
    if(T==NULL) return 0;
    else
    {
        Browse_RNL(T, count);
    }
    return count;

}
int main()
{
    TREE T;
    T = NULL;
    CreateTree(T);
    cout<<CountNode(T);
    return 0;
}
