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

int find(tree* t,int n)
{
    if(t==NULL)return 0;
    else if(t->data<n)return find(t->rc,n);
    else if(t->data>n)return find(t->lc,n);
    else return 1;
}

int Getturns(tree* t,int n,int i)
{
   if(t->data>n)
   {
    if(i==0)return (1+Getturns(t->lc,n,1));
    else return Getturns(t->lc,n,1);
   }
   else if(t->data<n)
   {
    if(i==1)return (1+ Getturns(t->rc,n,0));
    else return Getturns(t->rc,n,0);
   }
   else return 0;
}

int Get(tree* t,int n,int m)
{
    int a=find(t->lc,n);
    int b=find(t->rc,n);
    int c=find(t->lc,m);
    int d=find(t->rc,m);
    if(t->data==n)
    {
        return Getturns(t,m,-1);
    }
    else if(t->data==m)
    {
        return Getturns(t,n,-1);
    }
    else if(a==1 && c==1) return Get(t->lc,n,m);
    else if(b==1 && d==1)return Get(t->rc,n,m);
    else return (1+Getturns(t,m,-1)+Getturns(t,n,-1));
}

int main()
{
  int n;cin>>n;
  tree* t=new tree(n);
  cin>>n;
  while(n!=-1){   create(t,n);   cin>>n;};
   int k1,k2;
 cin>>k1>>k2;
 while(k1!=-1 && k2!=-1)
 {
 cout<<"hi "<<Get(t,k1,k2)<<endl;
 cin>>k1>>k2;
 }
 return 0;
}