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
void CreateEmptyList(LIST &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}
NODE* CreateNode(int x)
{
    NODE* p;
    p = new NODE;
    if(p==NULL) exit(1);
    else
    {
        p->info=x;
        p->pNext=NULL;
    }
    return p;
}
void AddTail(LIST &L, NODE*p)
{
    if(L.pHead==NULL)
    {
        L.pHead=p;
        L.pTail = L.pHead;
    }
    else
    {
        L.pTail->pNext=p;
        L.pTail=p;
    }
}
void CreateList(LIST &L)
{
    int x;
    while(1)
    {
        cin>>x;
        if(x==-1) return ;
        else
        {
            AddTail(L, CreateNode(x));
        }
    }

}
void RemoveHead(LIST &L)
{
    if(L.pHead==NULL) return;
    else
    {
        NODE* p;
        p = L.pHead;
        L.pHead = p->pNext;
        if(L.pHead==NULL)
            L.pTail==NULL;
    }
}
void PrintList(LIST L)
{
    if(L.pHead==NULL) cout<<"Empty List.";
    else
    {
        while(L.pHead!=NULL)
        {
            cout<<L.pHead->info<<" ";
            L.pHead=L.pHead->pNext;
        }
    }
}
int main()
{
    LIST L;
    CreateEmptyList(L);
    CreateList(L);
    RemoveHead(L);
    PrintList(L);
    return 0;
}
