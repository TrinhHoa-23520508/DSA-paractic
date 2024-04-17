#include<iostream>
#include<string>
using namespace std;
struct NODE
{
    int infor;
    NODE* pNext;
};
NODE* CreateNode(int x)
{
    NODE* p;
    p = new NODE;
    if(p==NULL) exit(1);
    else
    {
        p->infor= x;
        p->pNext = NULL;
    }
    return p;
}
void AddList(NODE* &pHead, NODE* p)
{
    if(pHead==NULL)//danh sach rong
        pHead = p;
    else{
        NODE* temp = pHead;
        while(temp->pNext!=NULL)
        {
            temp=temp->pNext;
        }
        temp->pNext=p;
    }
}
void CreateList(NODE* &pHead)
{
   int x;
   while(1)
   {
       cin>>x;
       if(x==-1) break;
       else
       {
          AddList(pHead, CreateNode(x));
       }
   }
}
/*string searchX(NODE* pHead, int x)
{
    if(pHead==NULL) return "false";
    else
    {
        NODE* temp;
        temp = pHead;
        while(temp->infor!=x&&temp!=NULL)
        {
            temp = temp->pNext;
        }
        if(temp!=NULL) return "true";
        else return "false";
    }
}*/
string searchX(NODE* pHead, int x)
{
    if(pHead==NULL) return "false";
    else
    {
        NODE* temp;
        temp = pHead;
        while(temp!=NULL && temp->infor!=x)
        {
            temp = temp->pNext;
        }
        if(temp!=NULL) return "true";
        else return "false";
    }
}


int main()
{
    NODE* pHead;
    int X;
    pHead=NULL;
    CreateList(pHead);
    std::cin>>X;
    cout<<searchX(pHead, X);
    return 0;

}
