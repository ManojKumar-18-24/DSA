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

void createetree(tree* &t)
{
    char ch;cin>>ch;
    if(ch!='#')
    {
        t=new tree(ch);
        createetree(t->lc);
        createetree(t->rc);
    }
}

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

int main()
{
    tree* t;
    createetree(t);
    stack M;
    push(M,t);int count=1;
    while(M.top!=-1)
    {
       tree * g=pop(M);
       cout<<g->data;
      if(g->rc!=NULL){ push(M,g->rc);count++;}
      if(g->lc!=NULL) {push(M,g->lc);count++;}
    }
    cout<<endl<<count<<endl;
    count=1;
    push(M,t);
    tree* g=t->lc;
    while(1)
    {
       while(g!=NULL)
       {
        push(M,g);count++;g=g->lc;
       }
       g=pop(M); cout<<g->data;
       while(M.top!=-1 &&  g->rc==NULL)
       {
         
          g=pop(M);
          cout<<g->data;
       } 
       if(g->rc==NULL && M.top==-1)break; 
       g=g->rc;
    }
     cout<<endl<<count;
   return 0;
}