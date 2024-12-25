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

void thrill(tree* t,int min=0,int max=9999)
{
   if(t!=NULL)
   {
       if(t->rc==NULL && t->lc!=NULL)
       {
           tree* g=new tree((max+t->data)/2);
           if(g->data==39)g->data=40;t->rc=g;
           thrill(t->lc,min,t->data-1);
       }
       else if(t->lc==NULL && t->rc!=NULL)
       {
           tree* g=new tree((min+t->data)/2);
            if(g->data==39)g->data=40;t->lc=g;
           thrill(t->rc,t->data+1,max);
       }
       else
        {
             thrill(t->lc,min,t->data-1);
             thrill(t->rc,t->data+1,max);
        }
   }
}

int main()
{
  int n;cin>>n;
  tree* t=new tree(n);
  cin>>n;
  while(n!=-1)
  {
     create(t,n);
     cin>>n;
  };
  thrill(t);
  printinorder(t);cout<<endl;
  preorderprint(t);
  return 0;
}