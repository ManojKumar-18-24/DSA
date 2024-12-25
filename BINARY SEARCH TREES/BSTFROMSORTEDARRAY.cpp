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

void create(tree* &t,int a[100],int high,int low=0)
{
  int m=high,n=low;
  while(n<m)
  {
    m--;n++;
  }
  t=new tree(a[n]);
  if(n-1>=low)create(t->lc,a,n-1,low);
  if(n+1<=high) create(t->rc,a,high,n+1);
}

int main()
{
  tree* t;int a[100]={0},k=1;
  int n;cin>>n;a[0]=n;
  cin>>n;
  while(n!=-1)
  {
    a[k]=n;k++;
    cin>>n;
  }
  create(t,a,k-1);
  preorderprint(t);
  return 0;
}