#include<iostream>
#include<queue>
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
        if(T->key==x) return 0;
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
void PrintTreeBFS(TREE T)
{
    if(T==NULL) cout<<"Empty Tree.";
    else
    {
        queue<pair<TNODE*, int>> q;
        q.push({T, 0});
        int flag = 0;
        while(!q.empty())
        {
            auto [node, level] = q.front();
            if(level!=flag) cout<<endl;
            cout<<node->key<<" ";
            flag = level;
            if(node->pLeft!=NULL) q.push({node->pLeft, level+1});
            if(node->pRight!=NULL) q.push({node->pRight, level+1});
            q.pop();

        }

    }
}
int main()
{
    TNODE* T;
    T = NULL;
    CreateTree(T);
    PrintTreeBFS(T);
    return 0;
}
