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

int e=0;

void print(tree* t,int j)
{
    if(t==NULL);
    else
    {
      print(t->lc,j);
      if(e>=j)cout<<t->data<<" ";
       e++;
      print(t->rc,j);
    }
}

void countorder(tree* t)
{
   static tree* temp=t;static int j=0;
   if(t==NULL);
   else
   {
    countorder(t->lc);
   e=0;print(temp,j); j++;cout<<endl;
    countorder(t->rc);
   }
}

void createbtree(tree* &t)
{
  int n;cin>>n;
  if(n!=0)
  {
    t=new tree(n);
    createbtree(t->lc);
    createbtree(t->rc);
  }
}

int main()
{
  tree* t;
  createbtree(t);
  countorder(t);
  return 0;
}