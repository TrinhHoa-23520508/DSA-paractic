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
void CreateEmptyList(LIST &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}
void AddTail(LIST &l, int x)
{
    NODE* p =CreateNode(x);
    if(l.pHead == NULL)
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
void CreateList(LIST &l, int &size)
{
    cin>>size;
    int x;
    for(int i = 0; i<size; i++)
    {
        cin>>x;
        AddTail(l, x);
    }
}
void PrintList(LIST l, int size)
{
    cout<<size<<endl;
    while(l.pHead!=NULL)
    {
        cout<<l.pHead->info<<" ";
        l.pHead = l.pHead -> pNext;
    }
}
int main()
{
    int size;
    LIST l;
    CreateEmptyList(l);
    CreateList(l, size);
    PrintList(l, size);
    return 0;
}
