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
    if(p == NULL) exit(1);
    else
    {
        p->info = x;
        p->pNext = NULL;
    }
    return p;
}
void AddTail(LIST &l, int x)
{
    NODE* p = CreateNode(x);
    if(l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = l.pHead;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
void RemoveTail(LIST &l)
{
    if(l.pHead == NULL&&l.pTail==NULL) return;
    else if(l.pHead == l.pTail)
    {
        delete l.pHead;
        l.pHead = NULL;
        l.pTail = NULL;
    }
    else
    {
       NODE* temp = l.pHead;
       while(temp -> pNext !=l.pTail)
       {
           temp = temp->pNext;
       }
       delete temp->pNext;
       temp -> pNext = NULL;
       l.pTail = temp;
    }
}
bool EmptyList(LIST l)
{
    if(l.pHead==NULL&&l.pTail==NULL) return 1;
    return 0;
}
class stack
{
private:
    LIST l;
public:
    stack()
    {
        l.pHead = NULL;
        l.pTail = NULL;
    }
    void push(int x);
    void pod();
    int top();
    bool EmptyStack();
};
bool stack::EmptyStack()
{
    return EmptyList(l);
}
void stack::push(int x)
{
    AddTail(l, x);
}
void stack::pod()
{
    RemoveTail(l);
}
int stack::top()
{
    NODE *temp = l.pHead;
    if( l.pHead==NULL) exit(1);
    else
    {
        while(temp ->pNext!=NULL)
        {
            temp = temp -> pNext;
        }
        return temp->info;
    }

}
void Testing_Push_Pop_Top_Stack(stack &s)
{
    int x;
    int *a;
    a = new int[100];
    int i = 0;
    cin>>x;
    while(x != -1)
    {
        if(s.EmptyStack()&&x==0)
        {
            cin>>x;
            continue;
        }
        else
        {
            if(x==0)
            {
                a[i++]=s.top();
                s.pod();
            }
            else
            {
                s.push(x);
            }
            cin>>x;
        }


    }
    cout<<"output: ";
    for(int j = 0; j<i; j++)
    {
        cout<<a[j]<<" ";
    }
    cout<<endl;
    if(!s.EmptyStack())
    {
        cout<<"top: "<<s.top();
    }
    else cout<<"top: ";
    delete[] a;
}
int main()
{
    stack s;
    Testing_Push_Pop_Top_Stack(s);
    return 0;
}
