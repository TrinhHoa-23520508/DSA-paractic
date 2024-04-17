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
    NODE* p = new NODE;
    if(p == NULL)
    {
        cout<<"Khong du bo nho de cap phat!\n";
        return NULL;
    }
    else
    {
        p -> info = x;
        p -> pNext = NULL;
        return p;
    }
}
void RemoveHead(LIST &l)
{
    if(l.pHead==NULL) return;
    else
    {
        NODE* p = l.pHead;
        l.pHead = l.pHead -> pNext;
        if(l.pHead == NULL)
            l.pTail = NULL;
        delete p;
    }
}
void AddTail(LIST &l, int x)
{
    NODE* p = CreateNode(x);
    if(l.pHead == NULL)//danh sach don rong
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        l.pTail -> pNext = p;
        l.pTail = p;
    }
}
void CreateList(LIST &L)
{
    int x;
    while(1)//cho vong lap chay den khi break
    {
        cin>>x;
        if(x==-1) break;
        else
        {
            AddTail(L, x);
        }

    }
}
void PrintList(LIST l)
{
    if(l.pHead == NULL)
    {
        cout<<"Empty List.\n";
        return;
    }
    else
    {
        while(l.pHead!=NULL)
        {
            cout<<l.pHead->info<<" ";
            l.pHead = l.pHead -> pNext;
        }
    }
    cout<<endl;
}
void Partition(LIST &l, LIST &l1, NODE* &pivot, LIST &l2)
{
    pivot = l.pHead;
    l.pHead = l.pHead->pNext;
    while(l.pHead!=NULL)
    {
        if(l.pHead->info<=pivot->info)
        {
            AddTail(l1, l.pHead->info);
        }
        else
        {
            AddTail(l2, l.pHead->info);
        }
        RemoveHead(l);
    }

}
int main()
{
    LIST L, L1, L2;
    NODE* pivot;
    CreateEmptyList(L);
    CreateEmptyList(L1);
    CreateEmptyList(L2);
    CreateList(L);
    if(L.pHead==NULL)
    {
        cout<<"Empty List.";
        return 0;
    }
    Partition(L, L1, pivot, L2);
    cout<<pivot->info<<endl;
    PrintList(L1);
    PrintList(L2);
    PrintList(L);
    return 0;
}
