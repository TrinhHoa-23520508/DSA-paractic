#include<iostream>
using namespace std;
#define MAXN 100
struct NODE
{
    char info;
    NODE* pNext;
};
NODE* CreateNode(char x)
{
    NODE* p = new NODE;
    p->info = x;
    p->pNext = NULL;
    return p;
}
struct stack
{
    NODE* top;
};
bool empty(const stack &s)
{
    return (s.top == NULL);
}
void CreateEmptyStack(stack &s)
{
    s.top = NULL;
}
void push(stack &s, char x)
{
    NODE* p = CreateNode(x);
    if(empty(s)) s.top = p;
    else
    {
        p->pNext = s.top;
        s.top = p;
    }
}
void pop(stack &s)
{
    if(empty(s)) return;
    else
    {
        NODE* p;
        p = s.top;
        s.top = s.top->pNext;
        delete p;
    }
}
char & top(stack s)
{
    return s.top->info;
}
void Input_infix()
int main()
{
    char infix[MAXN], postfix[MAXN];
    int ni, np;
    Input_infix(infix, ni);
    infix_to_postfix(infix, ni, postfix, np);
    Output(postfix, np);
    return 0;
}
