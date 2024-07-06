#include<iostream>
using namespace std;
#define MAXTABLESIZE 10000
struct NODE
{
    int key;
};
typedef NODE* HASHTABLE[MAXTABLESIZE];
int TableSize;
int M;
int HF(int key)
{
    return key%M;
}
int HF_LinearProbing(int key, int i)
{
    return (HF(key)+i)%TableSize;
}
NODE* CreateNode(int x)
{
    NODE* p = new NODE;
    p -> key = x;
    return p;
}
void CreateHashTable(HASHTABLE H, int &CurrentSize)
{
    cin>>M;
    cin>>TableSize;
    CurrentSize = M;
    for(int i = 0; i<CurrentSize; i++)
    {
        H[i] = NULL;
    }
    int x;
    int count = 0;
    while(1)
    {
        cin>>x;
        if(x==-1) break;
        else if(count==CurrentSize) continue;
        else
        {
            int i = HF(x);
            if(H[i]==NULL) H[i] = CreateNode(x);
            else
            {
                int j = 1;
                while(H[i]!=NULL)
                {
                    i = HF_LinearProbing(x, j);
                    j++;
                }
                H[i] = CreateNode(x);
            }
        }
        count++;
    }
}
void Traverse(HASHTABLE H, int CurrentSize)
{
    for(int i = 0; i<CurrentSize; i++)
    {
        cout<<i;
        if(H[i]!=NULL)
        {
            cout<<" --> "<<H[i]->key;
        }
        else
        {
            cout<<" --> "<<-1;
        }
        cout<<endl;
    }
}
int main()
{
    HASHTABLE H;
    int CurrentSize;
    CreateHashTable(H, CurrentSize);
    Traverse(H, CurrentSize);
    return 0;
}
