#include<iostream>
#include<string>
using namespace std;
#define LOAD 0.7
#define EMPTY 0
#define DELETED -1
#define OCCUPIED 1
struct NODE
{
    int flag;
    int key;
};
struct HASHTABLE
{
    int M;//Kich thuoc bang bam
    int n;//so phan tu hien tai trong bang bam
    NODE* table;
};
int HF(const HASHTABLE &ht, int key)
{
    return key%ht.M;

}
int HF_LinearProbing(const HASHTABLE &ht, int key, int i)
{
    int h = HF(ht, key);
    return (h+i)%ht.M;
}
bool isFull(HASHTABLE ht)
{
    if(ht.n==7) return true;
    return false;
}
int Insert(HASHTABLE &ht, int x)
{
    if(isFull(ht)) return -2;
    int i = HF(ht, x);
    int j = 0;
    while(ht.table[i].flag==OCCUPIED&&i<ht.M)
    {
        if(ht.table[i].key==x) return -1;
        i = HF_LinearProbing(ht, x, ++j);
    }
        ht.table[i].key = x;
        ht.table[i].flag = OCCUPIED;
        ht.n++;
        return i;

}
int Delete(HASHTABLE &ht, int x)
{
    int i = HF(ht, x);
    int j = 0;
    int temp = i;
    while(ht.table[temp].flag!=OCCUPIED||(ht.table[temp].flag==OCCUPIED&&ht.table[temp].key!=x))
    {
        temp = HF_LinearProbing(ht, x, ++j);
        if(temp == i) return -1;
    }
        ht.table[temp].flag = DELETED;
        ht.n--;
        return temp;
}
void CreateHashTable(HASHTABLE &ht)
{
    cin>>ht.M;
    ht.table = new NODE [ht.M];
    ht.n = 0;
    for(int i = 0; i<ht.M; i++)
    {
        ht.table[i].flag = 0;
    }
    int num;
    cin>>num;
    int A;
    int B;
    while(num>0)
    {
        cin>>A;
        cin>>B;
        if(A==0)
        {
            Delete(ht, B);
        }
        if(A==1)
        {
            Insert(ht, B);
        }
        num--;

    }
}
void Traverse(HASHTABLE ht)
{
    for(int i = 0; i<ht.M; i++)
    {
        cout<<i<<" --> ";
        if(ht.table[i].flag == -1) cout<<"DELETED";
        if(ht.table[i].flag == 0) cout<<"EMPTY";
        if(ht.table[i].flag == 1) cout<<ht.table[i].key;
        cout<<endl;
    }
}
void DeleteHashtable(HASHTABLE &ht)
{
    delete[]ht.table;
    ht.table = NULL;
    ht.M = 0;
}
int main()
{
    HASHTABLE H;
    CreateHashTable(H);
    Traverse(H);
    DeleteHashtable(H);
    return 0;
}
