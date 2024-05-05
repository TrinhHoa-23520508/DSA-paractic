#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
struct NODE
{
    int info;
    NODE* pNext;
} ;
struct LIST
{
    NODE* pHead;
    NODE* pTail;
};
NODE* CreateNode(int x)
{
    NODE* p;
    p = new NODE;
    p -> info = x;
    p -> pNext = NULL;
   return p;
}
void AddTail(LIST &L, NODE* p)
{
    if(L.pHead == NULL)
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
void CreateList(LIST&L)
{
    NODE* p;
    int x, n;
    cin>>n;
    while(n-->0)
    {
        cin>>x;
        p = CreateNode(x);
        AddTail(L, p);
    }
}
int length(NODE*p)
{
    int i = 0;
    while(p)
    {
        i++;
        p=p->pNext;
    }
    return i;
}
void PrintList(NODE* p)
{
    if(p == NULL)
    {
        cout<<"Empty List.";

    }
    else
    {
        cout<<length(p)<<endl;
        while(p)
        {
            cout<<p->info<<" ";
            p = p->pNext;
        }
    }
}
NODE*  SeparateHead(LIST&L)
{
    NODE* p;
    if(L.pHead==NULL) return NULL;
    else
    {
        p = L.pHead;
        L.pHead = L.pHead ->pNext;
        if(L.pHead==NULL)
            L.pTail = NULL;
        p->pNext = NULL;
        return p;
    }

}
void MergeSplit(LIST&  L, LIST &L1, LIST &L2)
{
    NODE* p;
    CreateEmptyList(L1);
    CreateEmptyList(L2);
    while(L.pHead)
    {
        p = SeparateHead(L);
        AddTail(L1, p);
        if(L.pHead)
            {
                p = SeparateHead(L);
                AddTail(L2, p);
            }
    }
}
void Merge(LIST &L, LIST &L1, LIST &L2)
{
    NODE* p;
    CreateEmptyList(L);
    while(L1.pHead!=NULL||L2.pHead!=NULL)
    {
        if(L1.pHead==NULL||(L2.pHead!=NULL&&L2.pHead->info<L1.pHead->info))
            {
                p = SeparateHead(L2);
                AddTail(L, p);
            }
        else
        {
            p = SeparateHead(L1);
            AddTail(L, p);
        }
    }


}
void mergesort_ascending(LIST &L)
{
    if(L.pHead == L.pTail) return ;
    LIST L1, L2;
    MergeSplit(L, L1, L2);
    mergesort_ascending(L1);
    mergesort_ascending(L2);
    Merge(L, L1, L2);

}
int main()
{
    LIST L;
    CreateEmptyList(L);
    CreateList(L);
    mergesort_ascending(L);
    PrintList(L.pHead);
    return 0;
}
