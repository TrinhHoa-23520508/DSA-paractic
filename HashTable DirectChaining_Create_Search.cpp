#include<iostream>
using namespace std;
#define M 100
struct NODE
{
    int key;
    NODE* pNext;
};
typedef NODE* NODEPTR;
typedef NODEPTR HASHTABLE[M];
NODE* CreateNode(int x)
{
    NODE* p = new NODE;
    p -> key = x;
    p ->  pNext = NULL;
    return p;
}
void AddTail(NODE* &head, int x)
{
    if(head == NULL) head = CreateNode(x);
    else
    {
        NODE* temp;
        temp = head;
        while(temp->pNext!=NULL)
        {
            temp = temp -> pNext;

        }
        temp -> pNext = CreateNode(x);
    }
}
int HF(int numbucket, int key)
{
    return key%numbucket;
}
void CreateHashTable(HASHTABLE H, int &numbucket)
{
    cin>>numbucket;
    for(int i = 0; i<numbucket; i++)
    {
        H[i] = NULL;
    }
    int x;
    while(1)
    {
        cin>>x;
        if(x==-1) break;
        else
        {
            AddTail(H[HF(numbucket, x)], x);
        }
    }

}
void Traverse(HASHTABLE H, int numbucket)
{
    for(int i = 0; i<numbucket; i++)
    {
        cout<<i;
        NODEPTR temp = H[i];
        while(temp)
        {
            cout<<" --> "<<temp->key;
            temp = temp -> pNext;
        }
        cout<<endl;

    }
}
int Search(HASHTABLE H,  int numbucket, int x)
{
    for(int i = 0; i < numbucket; i++)
    {
        NODEPTR temp;
        temp = H[i];
        while(temp!=NULL)
        {
            if(temp -> key==x) return i;
            else temp = temp -> pNext;
        }
    }
    return -1;

}
int main()
{
    HASHTABLE H;
    int numbucket;
    int x;
    CreateHashTable(H, numbucket);
    Traverse(H, numbucket);
    cin>>x;
    int i = Search(H, numbucket, x);
    cout<<endl;
    if(i==-1)
    {
        cout<<x<<" not found.";
    }
    else
    {
        cout<<x<<" found in bucket "<<i<<".";
    }
    return 0;
}
