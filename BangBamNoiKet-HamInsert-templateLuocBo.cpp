#include <iostream>
#include <string>

#define LOAD 0.7
using namespace std;

struct Hocsinh {
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};

struct Node {
    Hocsinh data;
    Node *next;
};

struct List {
    Node * head, *tail;
};

Node * CreateNode(Hocsinh);
void CreateEmptyList(List &);
void AddTail(List&, Hocsinh);
int RemoveHead(List &);
int RemoveAfter(List &, Node *);
void DeleteList(List &);

struct Hashtable {
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    List *table;
};

void CreateEmptyHashtable(Hashtable &, int);
int Hash(Hashtable, int); // Ham bam ma so hoc sinh thanh chi so
int Insert(Hashtable &, Hocsinh);
void PrintHashtable(Hashtable);
void DeleteHashtable(Hashtable &);

void Input(Hocsinh &);
int main()
{
    Hashtable hashtable;

    int m, n;
    Hocsinh hs;

    cin >> m;
    CreateEmptyHashtable(hashtable, m);
    cin >> n;
    for (int i = 0; i < n; i++) {
        Input(hs);
        Insert(hashtable, hs);
    }
    PrintHashtable(hashtable);
    DeleteHashtable(hashtable);
    return 0;
}


void DeleteList(List &l) {
    while (l.head) {
        Node *p = l.head;
        l.head = p->next;
        delete p;
    }
    l.head = l.tail = NULL;
}


int Hash(Hashtable ht, int maso) {
    return maso % ht.M;
}

void PrintHashtable(Hashtable ht) {
    for (int i = 0; i < ht.M; i ++) {
        Node *p = ht.table[i].head;
        while (p) {
            Hocsinh hs = p->data;
            cout << '[' << hs.Maso << ",  " << hs.Hoten << "  , " << hs.Gioitinh << ", " << hs.Namsinh << ", " << hs.TBK << "] ";
            p = p->next;
        }
        cout << '\n';
    }
}

void DeleteHashtable(Hashtable &ht) {
    for (int i = 0; i < ht.M; i++) {
        DeleteList(ht.table[i]);
    }
    delete [] ht.table;
    ht.table = NULL;
    ht.M = 0;
}

Node* CreateNode(Hocsinh x)
{
    Node* p = new Node;
    p -> data = x;
    p -> next = NULL;
    return p;
}
void CreateEmptyList(List &L)
{
void AddTail(List &L, Hocsinh x)
{
void DeleteList(List & L)
{
void CreateEmptyHashtable(Hashtable H, int m)
{
void Input(Hocsinh &hs)
{
    cin>>hs.Maso;
    getline(cin, hs.Hoten);
    cin>>Namsinh;
    cin>>Gioitinh;
    cin>>TBK;
}
void Insert(Hashtable &H, Hocsinh hs)
{

}
    H.M = m;
    H.table = new List [H.M];
    for(int i = 0; i<H.M; i++)
    {
        CreateEmptyList(H.table[i]);
    }
}
     if(L.head == L.tail) return;
    else
    {
        while(L.head)
        {
            Node* temp = L.head;
            L.head = L.head -> next;
            delete temp;
        }
        L.tail = L.head;
    }
}
    Node* p = CreateNode(x);
    if(L.head == NULL)
    {
        L.head = p;
        L.tail = L.head;
    }
    else
    {
        L.tail->next = p;
        L.tail = p
    }
}
    L.head = NULL;
    L.tail = NULL;
}
