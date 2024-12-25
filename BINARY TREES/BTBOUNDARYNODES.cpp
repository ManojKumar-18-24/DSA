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

void createbtree(tree* &t)
{
    int ch;cin>>ch;
    if(ch!=0)
    {
        t=new tree(ch);
        createbtree(t->lc);
        createbtree(t->rc);
    }
}

void printleftview(tree* t,int i=0)
{
  static int p=-1;
  if(t==NULL);
  else
  {
     if(i>p){ if(t->lc!=NULL ||t->rc!=NULL)cout<<t->data<<" ";p=i;}
     printleftview(t->lc,i+1);
     printleftview(t->rc,i+1);
  }
}

void PrintLeafNodes(tree* t)
{
    if(t!=NULL)
    {
        if(t->lc==NULL && t->rc==NULL)cout<<t->data<<" ";
        else
        {
            PrintLeafNodes(t->lc);
            PrintLeafNodes(t->rc);
        }
    }
}

void printrightview(tree* t,int i=0)
{
  static int p=-1;
  if(t==NULL);
  else
  {
    int q=0;
     if(i>p){q=1;p=i;}
     printrightview(t->rc,i+1);
     printrightview(t->lc,i+1);
     if(q==1)cout<<t->data<<" ";
  }
}

int main()
{   tree* t=NULL;
    createbtree(t);
    printleftview(t);
    PrintLeafNodes(t);
    printrightview(t);
    return 0;
}