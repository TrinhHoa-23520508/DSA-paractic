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
    int M;//kich thuoc bang bam
    int n;//so phan tu hien tai trong bang bam
    NODE* table;
};
int HF(HASHTABLE ht, int key)
{
    return key%ht.M;
}
int HF_LinearProbing(HASHTABLE ht, int key, int i)
{
    int h = HF(ht, key);
    return (h+i)%ht.M;
}
void DeleteHashtable(HASHTABLE &ht)
{
    delete[] ht.table;
    ht.table = NULL;
    ht.M = 0;

}
NODE CreateNode(int x)
{
    NODE p;
    p.flag = 0;
    p.key = x;
    return p;
}
void CreateHashTable(HASHTABLE &H)
{
    cin>>H.M;
    H.n =  LOAD*H.M;
    H.table = new NODE[H.M];
    for(int i = 0; i<H.M; i++)
    {
        H.table[i].flag = 0;
    }
    int x;
    int dem = 0;
    while(1)
    {
        cin>>x;
        if(x==-1) break;
        if(dem==H.n) continue;
        else
        {
            int i = HF(H, x);
            int j = 1;
            if(H.table[i].flag ==1)
            {
                if(H.table[i].key == x)
                {
                    continue;
                }
                else
                {
                    while(H.table[i].flag==1)
            {

                i = HF_LinearProbing(H, x, j);
                j++;
            }
                }
            }
             H.table[i].key = x;
            H.table[i].flag = 1;
            dem++;
            }
        }
    }

void Traverse(HASHTABLE H)
{
    for(int i = 0; i<H.M; i++)
    {
        cout<<i;
        cout<<" --> ";
        if(H.table[i].flag==0||H.table[i].flag==-1) cout<<"EMPTY";
        if(H.table[i].flag==1) cout<<H.table[i].key;
        cout<<endl;
    }
}

int main()
{
    HASHTABLE H;
    CreateHashTable(H);
    Traverse(H);
    DeleteHashtable(H);
    return 0;
}
