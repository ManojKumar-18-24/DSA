#include<iostream>
using namespace std;

class dnode
{
  public:
  dnode* left;
  int data;
  dnode* right;
  dnode(int m)
    {
     left=NULL;
     right=NULL;
     data=m;
    }
};

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

void print(dnode* D)
{
  while(D!=NULL)
  {
    cout<<D->data<<" ";
    D=D->right;
  }
  cout<<endl;
}

void addend(dnode* D,int n)
{
  while(D->right!=NULL)
  {
   D=D->right;
  }
  dnode* g=new dnode(n);
  D->right=g;
  g->left=D;
}

int ComPare(dnode* s,dnode* p)
{
    while(s!=NULL)
    {
        if(s==p)return 1;
        s=s->right;
    }
    return 0;
}

void create(tree* &t,dnode* D,dnode* temp)
{
    dnode* SP=D;
    dnode* FP=D;
     while(FP!=temp)
     {
        SP=SP->right;
        FP=FP->right->right;
        if(FP==temp->right)break;
     }
     t=new tree(SP->data);
   if(ComPare(D,SP->left)) create(t->lc,D,SP->left);
   if(ComPare(SP->right,temp))create(t->rc,SP->right,temp);
    
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

int main()
{
    int n;cin>>n;
    dnode* D= new dnode(n);
    cin>>n;
    while(n!=-1)
     {
       addend(D,n);
      cin>>n;
     }
     dnode* temp=D;
     while(temp->right!=NULL)temp=temp->right;tree* t=NULL;
     create(t,D,temp);
     preorderprint(t);
     return 0;
}