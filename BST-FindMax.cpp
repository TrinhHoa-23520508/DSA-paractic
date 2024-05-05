#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;
TNODE* CreateTNode(int x)
{
    TNODE* p = new TNODE;
    p -> key = x;
    p -> pLeft = NULL;
    p -> pRight = NULL;
    return p;
}
void CreateEmptyTree(TREE &T)
{
    T = NULL;
}
int Insert(TREE &T, TNODE* p)
{
    if(T == NULL) T = p;
    else
    {
        TNODE* Root = T;
        while(Root!= NULL)
        {
            if(Root->key==p->key) return 0;
            if(Root->key<p->key)
            {
                if(Root->pRight==NULL)
                    Root->pRight = p;
                Root = Root->pRight;
            }
            else
            {
                if(Root->pLeft == NULL )
                    Root->pLeft = p;
                Root = Root->pLeft;
            }
        }
        Root = p;

    }
    return 1;
}
void CreateTree(TREE &T)
{
    int x;
    while(1)
    {
        cin>>x;
        if(x==-1) return;
        else
        {
            Insert(T, CreateTNode(x));
        }
    }
}
TNODE* FindMax(TREE T)
{
    TNODE* p = T;
    while(p->pRight!=NULL)
    {
        p=p->pRight;
    }
    return p;
}
int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	if(T==NULL) cout << "Empty Tree.";
	else cout << FindMax(T)->key;
	return 0;
}
