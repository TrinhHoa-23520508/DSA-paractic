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
        if(T->key<x) return Insert(T->pRight, x);
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
        if(x==-1) break;
        else
        {
            Insert(T, x);
        }
    }
}
int findLongestPathLength(TNODE* root) {
    if (!root) return 0;
    int leftDepth = findLongestPathLength(root->pLeft);
    int rightDepth = findLongestPathLength(root->pRight);
    return max(leftDepth, rightDepth) + 1;
}
int main()
{
    TREE T;
    T = NULL;
    CreateTree(T);
    cout<<findLongestPathLength(T);
    return 0;

}
