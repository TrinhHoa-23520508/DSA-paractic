#include<iostream>
using namespace std;
struct NODE
{
    int info;
    NODE* pNext;
};
struct LIST
{
    NODE * pHead;
    NODE* pTail;
};
NODE* CreateNODE(int x)
{
    NODE* p ;
    p = new NODE;
    p->info = x;
    p->pNext = NULL;
    return p;
}
void CreateEmptyList(LIST &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}
void AddTail(LIST &L, NODE* p)
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
void CreateList(LIST &L)
{
    int x;
    while(1)
    {
        cin>>x;
        if(x==-1) return;
        else
        {
            AddTail(L, CreateNODE(x));
        }
    }
}
NODE* SeparateHead(LIST &L)
{
    if(L.pHead==NULL) return NULL;
    else
    {
        NODE*p;
        p=L.pHead;
        L.pHead = L.pHead->pNext;
        if(L.pHead==NULL)
            L.pTail = NULL;
        p->pNext = NULL;
        return p;
    }

}
void Merge_2_Sorted_LL(LIST& L, LIST &L1, LIST &L2)
{
    CreateEmptyList(L);
    while(L1.pHead!=NULL&&L2.pHead!=NULL)
    {
        if(L1.pHead->info<L2.pHead->info)
            AddTail(L, SeparateHead(L1));
        else
            AddTail(L, SeparateHead(L2));
    }
    while(L1.pHead!=NULL)
    {
        AddTail(L, SeparateHead(L1));
    }
    while(L2.pHead!=NULL)
    {
        AddTail(L, SeparateHead(L2));
    }

}
void PrintList(LIST L)
{
    NODE* p;
    if(L.pHead == NULL)
        cout<<"Empty List.";
    else
    {
        p = L.pHead;
        while(p)
        {
            cout<<p->info<<" ";
            p = p->pNext;
        }
    }
    cout<<endl;
}
int main()
{
    LIST L, L1, L2;
    CreateEmptyList(L1);
    CreateEmptyList(L2);
    CreateList(L1);
    CreateList(L2);
    Merge_2_Sorted_LL(L, L1, L2);
    PrintList(L);
    PrintList(L1);
    PrintList(L2);
    return 0;
}
