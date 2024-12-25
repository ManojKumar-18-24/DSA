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

int find(int a[100],int start,int k)
{
    int n=a[start];
    while(start<k)
    {
        if(a[start]>n)break;start++;
    }
  return start;
}

void createfrompre(tree* &t,int a[100],int k,int start,int end)
{
   t=new tree(a[start]);
   int i=find(a,start,k);
 if(start<i-1) createfrompre(t->lc,a,k,start+1,i-1);
 if(i<=end) createfrompre(t->rc,a,k,i,end);
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

int main()
{
  int n,k=0;
  tree* t=NULL;int a[100];
  cin>>n;a[k]=n;
  k++;cin>>n;
  while(n!=-1) {   a[k]=n;k++;cin>>n; } 
  createfrompre(t,a,k,0,k-1);
  printinorder(t);
  return 0;
}