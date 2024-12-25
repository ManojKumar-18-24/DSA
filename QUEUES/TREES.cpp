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

void postorderprint(tree * t)
{
  if(t==NULL);
   else
   {
      
     postorderprint(t->lc);
     postorderprint(t->rc);
     cout<<t->data<<" ";
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

void printinorder(tree * t)
{
   if(t==NULL);
   else
   {
     printinorder(t->lc);
     cout<<t->data<<" ";
     printinorder(t->rc);
   }
}

int findmax(tree* t)
{
    if(t->rc==NULL)
    {
      return t->data;
    }
    return findmax(t->rc);
}

int findmin(tree *t)
{
   if(t->lc==NULL)
    {
      return t->data;
    }
    return findmin(t->lc);
}

int find(tree* t,int k)
{
  if(t==NULL)
  {
    return 0;
  }
  else if(k>t->data)
  {
    return find(t->rc,k);
  }
  else if(k<t->data)
  {
    return find(t->lc,k);
  }
  else
  {
    return 1;
  }
}

int main()
{
  int n;cin>>n;
  tree* t=new tree(n);
  cin>>n;
  while(n!=-1)
  {
     create(t,n);
     cin>>n;
  }
  preorderprint(t);cout<<endl;
  printinorder(t);cout<<endl;
  postorderprint(t);cout<<endl;
  cout<<findmax(t)<<endl;
  cout<<findmin(t)<<endl;
  cin>>n;
  cout<<find(t,n)<<endl;
  cin>>n;
  cout<<find(t,n)<<endl;
  return 0;
}
