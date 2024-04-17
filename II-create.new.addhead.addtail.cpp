#include<iostream>
using namespace std;
struct NODE
{
    int infor;
    NODE* pNext;
};
struct LIST
{
    NODE* pHead;
    NODE* pTail;
};
void CreateEmptyList(LIST &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}
NODE* CreateNode(int x)
{
    NODE*p;
    p=new NODE;
    if(p==NULL)
        exit(1);
    else
    {
        p->infor=x;
        p->pNext=NULL;
    }
    return p;
}
void AddHead(LIST &l, NODE* p)
{
    if(l.pHead==NULL)//danh sach rong
    {
        l.pHead=p;
        l.pTail=l.pHead;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
void AddTail(LIST &l, NODE* p)
{
    if(l.pHead==NULL)//danh sach rong
    {
        l.pHead = p;
        l.pTail = l.pHead;
    }
    else
    {
        l.pTail->pNext=p;
        l.pTail=p;
    }
}
void PrintList(LIST l)
{
    NODE*p = l.pHead;
    while(p!=NULL)
    {
        cout<<p->infor<<" ";
        p=p->pNext;
    }
}
int main()
{
    LIST l;
    CreateEmptyList(l);
    int x;
    while(1)
    {
        cin>>x;
        if(x==-1) break;
        else
        {
            int y;
            cin>>y;
            if(x==0) AddHead(l, CreateNode(y));
            else if(x==1) AddTail(l, CreateNode(y));
        }

    }
    PrintList(l);
    return 0;
}
