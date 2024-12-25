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

int findmax(tree* t)
{
    if(t->rc==NULL)
    {
      return t->data+1;
    }
    return findmax(t->rc);
}

int findmin(tree *t)
{
   if(t->lc==NULL)
    {
      return t->data-1;
    }
    return findmin(t->lc);
}

void printminmax(tree* t,int min=0,int max=99999)
{
    if(t!=NULL)
    {
        printminmax(t->lc,min,t->data-1);
        printminmax(t->rc,t->data+1,max);
     if(t->rc!=NULL && t->lc!=NULL)
     {
         cout<<t->data<<" ";cout<<findmin(t->rc)<<" ";
         cout<<findmax(t->lc)<<endl;
     }
     else if(t->rc==NULL && t->lc!=NULL)
     {
        cout<<t->data<<" ";cout<<findmax(t->lc)<<" ";cout<<max<<endl;
     }
     else if(t->lc==NULL && t->rc!=NULL)
     {
        cout<<t->data<<" ";cout<<min<<" ";cout<<findmin(t->rc);
     }
     else
     {
         cout<<t->data<<" "<<min<<" "<<max<<endl;
     }
    }
}

int main()
{
  int n;cin>>n;
  tree* t=new tree(n);
  cin>>n;
  while(n!=-1){   create(t,n);   cin>>n;};
  printminmax(t);
  return 0;
}