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

void exchange(tree* t,int n,int k)
{
    if(t==NULL);
    else if(t->data<k)
    {
        exchange(t->rc,n,k);
    }
    else if(t->data>k)
    {
        exchange(t->lc,n,k);
    }
    else
    {
        t->data=n;
    }
}

int is_BST(tree* t,int min=-99999,int max=99999)
{
    if(t!=NULL)
    {
        if(t->data>=min && t->data<=max)
        {
            is_BST(t->lc,min,t->data-1);
            is_BST(t->rc,t->data+1,max);
        }
        else
        {
            cout<<t->data<<endl;
        }
    }
}

void printpostorder(tree * t)
{
   if(t==NULL);
   else
   {
     cout<<t->data<<" ";
     printpostorder(t->lc);
     printpostorder(t->rc);
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
  exchange(t,16,27);
  is_BST(t);
  printpostorder(t);
  return 0;
}
          