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
    if(p == NULL)
    {
        cout<<"Khong du bo nho de cap phat!\n";
        return NULL;
    }
    else
    {
        p->info = x;
        p->pNext = NULL;
        return p;
    }
}
bool isEmptyList(LIST l)
{
    if(l.pHead == NULL) return true;
    return false;
}
void RemoveHead(LIST& l)
{
    if(isEmptyList(l)) exit(1);
    else
    {
        NODE* p = l.pHead;
        l.pHead = l.pHead -> pNext;
        if(l.pHead == NULL)
        {
            l.pTail = NULL;
        }
        delete p;
    }
}
void AddTail(LIST &l, int x)
{
    NODE* p = CreateNode(x);
    if(isEmptyList(l))
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
void CreateEmptyList(LIST &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}
void CreateList(LIST &l)
{
    int x;
    while(1)
    {
        cin>>x;
        if(x == -1 ) break;
        else
        {
            AddTail(l, x);
        }
    }

}
void Join(LIST &l, LIST &l1, NODE* &pivot, LIST &l2)
{
    int temp;
    while(!isEmptyList(l1))
    {
        temp = l1.pHead->info;
        AddTail(l, temp);
        RemoveHead(l1);
    }
    temp = pivot->info;
    AddTail(l, temp);
    while(!isEmptyList(l2))
    {

        temp = l2.pHead->info;
        AddTail(l, temp);
        RemoveHead(l2);

    }

}
void PrintList(LIST l)
{
    while(l.pHead!=NULL)
    {
        cout<<l.pHead -> info<<" ";
        l.pHead = l.pHead->pNext;
    }
    cout<<endl;
}
int main()
{
    LIST L, L1, L2;
    int x;
    NODE* pivot;
    CreateEmptyList(L);
    CreateEmptyList(L1);
    CreateEmptyList(L2);
    CreateList(L1);
    cin>>x;
    pivot = CreateNode(x);
    CreateList(L2);
    Join(L, L1, pivot, L2);
    PrintList(L);
    return 0;
}
