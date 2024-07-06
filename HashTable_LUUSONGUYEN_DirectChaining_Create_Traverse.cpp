#include<iostream>
#include<string>
using namespace std;
struct NODE
{
    int key;
    NODE* pNext;
};
struct LIST
{
    NODE* pHead;
    NODE* pTail;

};
struct HASHTABLE
{
    int M;// Kich thuoc bang bam
    int n;// So phan tu hien tai cua bang bam
    LIST *table;
};
int HF(HASHTABLE ht, int key)
{
    return key%ht.M;
}
NODE* CreateNode(int x)
{
    NODE* p = new NODE;
    p -> key = x;
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
        L.pTail -> pNext = p;
        L.pTail = p;
    }
}
void CreateHashTable(HASHTABLE &H)
{
    cin>>H.M;
    H.table = new LIST[H.M];
    H.n = 0;
    for(int i = 0; i<H.M; i++)
    {
        H.table[i].pHead = NULL;
        H.table[i].pTail = NULL;
    }
    int x;
    while(1)
    {
        cin>>x;
        if(x==-1) break;
        else
        {
            int i = HF(H, x);
            AddTail(H.table[i], CreateNode(x));
            H.n++;
        }
    }


}
void Traverse(HASHTABLE H)
{
    for(int i = 0; i<H.M; i++)
    {
        cout<<i;
        LIST temp = H.table[i];
        while(temp.pHead!=NULL)
        {
            cout<<" --> "<<temp.pHead->key;
            temp.pHead = temp.pHead->pNext;
        }
        cout<<endl;
    }
}
int main()
{
    HASHTABLE H;
    CreateHashTable(H);
    Traverse(H);
    return 0;
}
