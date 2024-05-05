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
    NODE* p = new NODE;
    p ->info = x;
    p ->pNext = NULL;
    return p;
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
void CreateEmptyList(LIST &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}
void CreateList(LIST &L)
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
void PrintList(LIST L)
{
    NODE* p;
    if(L.pHead == NULL)
        cout<<"Empty List.";
    else
    {
        while(L.pHead)
        {

        cout<<L.pHead->info<<" ";
        L.pHead = L.pHead->pNext;
        }
    }
    cout<<endl;
}
NODE* SeparateHead(LIST &L)
{
    NODE* p;
    if(L.pHead == NULL) return NULL;
    else
    {
        p = L.pHead;
        L.pHead = L.pHead->pNext;
        p->pNext = NULL;
        if(L.pHead == NULL)
            L.pTail=NULL;
        return p;
    }

}
void Merge_Partition(LIST& L, LIST &L1, LIST &L2)
{
    CreateEmptyList(L1);
    CreateEmptyList(L2);
    while(L.pHead)
    {
        NODE* p = SeparateHead(L);
        AddTail(L1, p);
        if(L.pHead)
        {
            NODE* p = SeparateHead(L);
            AddTail(L2, p);
        }
    }

}
int main()
{
    LIST L, L1, L2;
    CreateEmptyList(L);
    CreateList(L);
    Merge_Partition(L, L1, L2);
    PrintList(L1);
    PrintList(L2);
    PrintList(L);
    return 0;
}
