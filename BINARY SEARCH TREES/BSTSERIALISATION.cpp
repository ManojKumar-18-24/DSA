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

void print(tree*  t)
{
 if(t==NULL)cout<<0<<" ";
 else
 {
  cout<<t->data<<" ";
  print(t->lc);
  print(t->rc);
 
 }
}

void printin(tree*  t)
{
 if(t==NULL);
 else
 {
  printin(t->lc);
  cout<<t->data<<" ";
  printin(t->rc);
 }
}

void createbtree(tree* &t,int a[100],int size)
{
   static int i=0;
   if(i==size);
   else if(a[i]==0)
   {
     t=NULL;
   }
   else
   {
    t=new tree(a[i]);i++;
    createbtree(t->lc,a,size);i++;
    createbtree(t->rc,a,size);
   }
}

int main()
{
  int n;cin>>n;
  tree* t=new tree(n);
  cin>>n;
  while(n!=-1){   create(t,n);   cin>>n;};
  print(t);cout<<endl;
  int a[100],k=0;
  cin>>n;a[k]=n;
  k++;cin>>n;
  while(n!=-1)
  {
    a[k]=n;k++;cin>>n;
  } 
  tree* t2;
  createbtree(t2,a,k);
  printin(t2);
  return 0;
}