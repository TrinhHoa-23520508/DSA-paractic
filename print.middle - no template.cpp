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
void CreateList(NODE* &pHead, int &dem)
{
   int x;
   while(1)
   {
       cin>>x;
       if(x==-1) break;
       else
       {
          AddList(pHead, CreateNode(x));
          dem++;

       }
   }
}
void PrintMiddleList(NODE* pHead, int dem)
{
    int middle = (dem-1)/2;
    if(pHead==NULL) cout<<"Empty List.";
    else
    {
        while(middle!=0)
        {
           pHead=pHead->pNext;
           middle--;
        }
        cout<<pHead->infor;

    }


}



int main()
{
    NODE* pHead;
    int dem = 0;
    pHead=NULL;
    CreateList(pHead, dem);
    PrintMiddleList(pHead, dem);
    return 0;

}
