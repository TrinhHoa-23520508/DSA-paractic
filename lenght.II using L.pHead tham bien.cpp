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
int length(NODE* p)
{
    int dem = 0;
   while(p!=NULL)
   {
       dem++;
       p=p->pNext;

   }
   return dem;
}

int main()
{
    LIST L;
    CreateEmptyList(L);
    CreateList(L);
    cout<<length(L.pHead);
    return 0;
}
