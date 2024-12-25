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

void createbtree(tree* &t)
{
    char ch;cin>>ch;
    if(ch!='#')
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
     if(i>p){cout<<t->data<<" ";p=i;}
     printleftview(t->lc,i+1);
     printleftview(t->rc,i+1);
  }
}

void printrightview(tree* t,int i=0)
{
  static int p=-1;
  if(t==NULL);
  else
  {
     if(i>p){cout<<t->data<<" ";p=i;}
     printrightview(t->rc,i+1);
     printrightview(t->lc,i+1);
  }
}

int main()
{   tree* t=NULL;
    createbtree(t);
    printleftview(t);cout<<endl;
    printrightview(t);
    return 0;
}