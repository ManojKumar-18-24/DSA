#include<iostream>
using namespace std;

class tree
{
    public:
    tree* lc;
    char data;
    tree* rc;
    tree(int n)
    {
        lc=NULL;
        data=n;
        rc=NULL;
    }
};

void create(tree* &t,char k)
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

void printpre(tree*  t)
{
 if(t==NULL);
 else
 {
  cout<<t->data;
  printpre(t->lc);
  printpre(t->rc);
 
 }
}

void printin(tree*  t)
{
 if(t==NULL);
 else
 {
  printin(t->lc);
  cout<<t->data;
  printin(t->rc);
 }
}

void createbtree(tree* &t,char a[100],int size)
{
   static int i=0;
   if(i==size);
   else if(a[i]=='#')
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
  char n;
  tree* t;
  char a[100],k=0;
  cin>>n;a[k]=n;
  k++;cin>>n;
  while(n!='G')
  {
    a[k]=n;k++;cin>>n;
  } a[k]='G';k++;
  for(int i=0;i<3;i++)
  {
      a[k]='#';k++;
  }
  createbtree(t,a,k);
  printpre(t);cout<<endl;printin(t);
  return 0;
}