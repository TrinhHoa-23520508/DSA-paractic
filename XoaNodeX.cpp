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
#include<cmath>
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
void PrintLevel(TREE T, int level)
{
    if(T==NULL) cout<<"Empty Tree.";
    else
    {
        if(level<0) cout<<"Khong ton tai level "<<level<<".";
        else
        {
            queue<pair<TNODE*, int>> q;
            q.push({T, 0});
            int flag = 0;
            while(!q.empty())
            {
                auto [node, currentlevel] = q.front();
                if(currentlevel==level) {cout<<node->key<<" ";flag++;}
                if(node->pLeft!=NULL) q.push({node->pLeft, currentlevel+1});
                if(node->pRight!=NULL) q.push({node->pRight, currentlevel+1});
                q.pop();


            }
            if(flag==0) cout<<"Khong ton tai level "<<level<<".";
        }
    }


}
int main()
{
    TNODE* T;
    T = NULL;
    int level;
    cin>>level;
    CreateTree(T);
    PrintLevel(T, level);
    return 0;
}
