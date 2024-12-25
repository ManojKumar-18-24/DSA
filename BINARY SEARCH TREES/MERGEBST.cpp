#include<iostream>
using namespace std;

class tree
{
    public:
    tree* lc;
    int data;
    tree* rc;
    tree(int n)
    {
        lc=NULL;
        data=n;
        rc=NULL;
    }
};

struct stack
{
  int size=100;
  int elements[100];
  int top=-1;
};

int peep(stack &M)
{
     return (M.top==-1)?-1:M.elements[M.top];
}

int pop(stack &M)
{
    return ( M.top==-1)?-1: M.elements[M.top--];
}

void push(stack &M,int x)
{
  if(M.top==M.size-1);
  else
  { 
    M.top++;
    M.elements[M.top]=x;
  }
}

void create(tree* &t,int k)
{
   if(t==NULL)
   {
    t=new tree(k);
   }
   else if(t->data>k)
   {
     create(t->lc,k);
   }
   else 
   {
    create(t->rc,k);
   }
}

void pushintostack(tree* t,stack &M)
{
   if(t==NULL);
   else
   {
      pushintostack(t->rc,M);
      pushintostack(t->lc,M);
      push(M,t->data);
   }
}

void preorderprint(tree *t)
{
   if(t==NULL);
   else
   {
      cout<<t->data<<" ";
     preorderprint(t->lc);
     preorderprint(t->rc);
   }
}

int main()
{
  int n;cin>>n;
  stack M1,M2;
  tree* t1=new tree(n);
  cin>>n;
  while(n!=-1)
  {
     create(t1,n);
     cin>>n;
  };
  cin>>n;
  tree* t2=new tree(n);
  cin>>n;
  while(n!=-1)
  {
     create(t2,n);
     cin>>n;
  };
  pushintostack(t1,M1);
  pushintostack(t2,M2);tree*  t3;
  while(M1.top!=-1 || M2.top!=-1)
  {
   if(M1.top!=-1)  create(t3,pop(M1));
   if(M2.top!=-1) create(t3,pop(M2));
  }
  preorderprint(t3); 
  return 0;
}