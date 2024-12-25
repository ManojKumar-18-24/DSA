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

void createbtree(tree* &t,int a[],int n)
{
    static int i=0;
    if(i==n)return;
    else if(a[i]!=0)
    {
        t=new tree(a[i]);i++;
        createbtree(t->lc,a,n);i++;
        createbtree(t->rc,a,n);
    }
}

void change(tree* t)
{
    if(t==NULL);
    else
    {
        t->data=0;
        change(t->lc);
        change(t->rc);
    }
}

int minimum=9999;

void addtotree(tree* &t,int b[8])
{
    static int i=0;
  if(t==NULL)return;
  if(t->lc==NULL && t->rc==NULL)
  {
     tree* g=new tree(b[i]);
    t->lc=g;i++;
    g=new tree(b[i]);
    t->rc=g;i++;
  }
  else
  {
    addtotree(t->lc,b);
    addtotree(t->rc,b);
  }
}

void pullout(tree* t)
{
    static tree* temp=t;
    if(t==NULL)return;
    else if(t->lc==NULL && t->rc==NULL)
    {
       if(t->data<minimum && t->data!=0)
       {
          minimum=t->data;
       }
    }
    else
    {
        pullout(t->lc);
        pullout(t->rc);
    }
}

void find(tree* t,int key)
{
    if(t==NULL);
    else if( t->lc!=NULL && t->lc->data==key)
    {
        t->lc=NULL;
    }
    else if(t->rc!=NULL && t->rc->data==key)
    {
        t->rc=NULL;
    }
    else
    {
        find(t->lc,key);
        find(t->rc,key);
    }
}

int main()
{
    int a[]={1,2,4,0,0,5,0,0,3,6,0,0,7,0,0};
    tree* t; createbtree(t,a,15);
    change(t);
    int b[8];
    for(int i=0;i<8;i++)cin>>b[i];
    addtotree(t,b);int i=0;
  while(i<8)
  {  
    pullout(t);
    t->data=minimum;
    cout<<t->data<<" ";
    t->data=0;
    find(t,minimum);
    minimum=9999;i++;
  }
    return 0;
}