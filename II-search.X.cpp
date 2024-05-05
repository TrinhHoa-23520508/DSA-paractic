#include<iostream>
using namespace std;
struct NODE
{
    int info;
    NODE* pNext;
};
struct LIST
{
    NODE* pHead;
    NODE* pTail;
};
NODE* CreateNode(int x)
{
    NODE* p;
    p = new NODE;
    p->info = x;
    p->pNext = NULL;
    return p;
}
void AddTail(LIST& L, NODE* p)
{
    if(L.pHead==NULL)
    {
        L.pHead = p;
        L.pTail = L.pHead;
    }
    else
    {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}
void CreateEmptyList(LIST& L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}
void CreateList(LIST& L)
{
    int x;
    while(1)
    {
        cin>>x;
        if(x==-1) break;
        else
        {
            AddTail(L, CreateNode(x));
        }
    }
}
string searchX(NODE* p, int x)
{
    if(p==NULL) return "false";
    else
    {
        while(p!=NULL&&p->info!=x)
        {
            p = p->pNext;
        }
        if(p) return "true";
        return "false";
    }
}
int main()
{
    LIST L;
    int X;
    CreateEmptyList(L);
    CreateList(L);
    std::cin>>X;
    cout<<searchX(L.pHead, X);
    return 0;
}
