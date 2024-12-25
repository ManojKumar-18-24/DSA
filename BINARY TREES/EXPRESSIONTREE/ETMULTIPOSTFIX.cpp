#include<iostream>
using namespace std;

union two
{
   int x;
   char y;
};

class tree
{
    public:
    tree* lc;
    int flag;
    two data;
    tree* rc;
    tree()
    {
        lc=NULL;
        rc=NULL;
    }
};

struct stack
{
  int size=100;
  tree* elements[100];
  int top=-1;
};

tree* peep(stack &M)
{
    return (M.top==-1)? NULL:M.elements[M.top];
}

tree* pop(stack &M)
{
    return ( M.top==-1)?NULL: M.elements[M.top--];
}

void push(stack &M,tree* x)
{
  if(M.top==M.size-1);
  else
  { 
    M.top++;
    M.elements[M.top]=x;
  }
}

int eval(tree* t)
{
  if(t!=NULL)
  {
    if(t->flag==0)
    {  
         return t->data.x;
    }
    else
    {
        switch(t->data.y)
        {
            case '+':return eval(t->lc)+eval(t->rc);
            case '-':return eval(t->lc)-eval(t->rc);
            case '*':return eval(t->lc)*eval(t->rc);
            case '/':return eval(t->lc)/eval(t->rc);
        }
    }
  }
}

void createetree(stack &M)
{
    int n;
    cin>>n;
    if(n==0)
    {    cin>>n;
        if(n==0)
        {
            cout<<eval(pop(M));
        }
        tree* g=new tree;
        g->flag=0;
        g->data.x=n;push(M,g);
    }
    else
    {  char ch;cin>>ch;
        tree* g=new tree;
        g->flag=1;
        g->data.y=ch;
        g->rc=pop(M);
        g->lc=pop(M);push(M,g);
    }
    createetree(M);
}

int main()
{
    stack M;
   createetree(M);
    return 0;
}