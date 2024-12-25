#include<iostream>
using namespace std;

class tree
{
    public:
    tree* lc;
    char data;
    tree* rc;
    tree(char n)
    {
        lc=NULL;
        data=n;
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
    if(t->data>='0')
       return (t->data-'0');
    else
    {
        switch(t->data)
        {
            case '+':return eval(t->lc)+eval(t->rc);
            case '-':return eval(t->lc)-eval(t->rc);
            case '*':return eval(t->lc)*eval(t->rc);
            case '/':return eval(t->lc)/eval(t->rc);
        }
    }
  }
}

void createetree(tree* &t,string s,stack &M)
{
    static int i=0;
    if(i==s.length())
    {
        cout<<eval(pop(M));return;
    }
    if(s[i]>='0')
    {
        tree* g=new tree(s[i]);
        push(M,g);
    }
    else
    {
        tree* g=new tree(s[i]);
        g->rc=pop(M);
        g->lc=pop(M);
        push(M,g);
    } i++;
   createetree(t,s,M);
}

int main()
{
    tree* t=NULL;
    string str;
    cin>>str;stack M;
    createetree(t,str,M);
    return 0;
}