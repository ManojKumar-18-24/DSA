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

void print(dnode* D)
{
  while(D!=NULL)
  {
    cout<<D->data<<" ";
    D=D->right;
  }
  cout<<endl;
}

void addfront(dnode* &D,int n)
{
  dnode* g=new dnode(n);
  g->right=D;
  D->left=g;
  g->left=D;
  D=g;
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

void addbefore(dnode* &D,int x,int y)
{
  dnode* temp=D;
  if(temp->data==y)
  {
    dnode* g=new dnode(x);
    D->left=g;
    g->right=D;
    D=g;
    return;
  }
  while((temp->right)->data!=y)
  {
    temp=temp->right;
  }
  dnode* g=new dnode(x);
  temp->right->left=g;
  g->right=temp->right;
  temp->right=g;
  g->left=temp;
}

void addafter(dnode* D,int x,int y)
{
  dnode* temp=D;
  dnode* g=new dnode(x);
  if(temp->data==y)
  {
     D->right->left=g;
     g->right=D->right;
     D->right=g;
     g->left=D;
    return;
  }
  while(temp->data!=y)
  {
    temp=temp->right;
  }
  if(temp->right==NULL)
  {
    temp->right=g;
    g->left=temp;
    return;
  }
  temp->right->left=g;
  g->right=temp->right;
  temp->right=g;
  g->left=temp;
}

void deletefront(dnode* &D)
{
   if(D->right==NULL)
     {
        D=NULL;
        return;
      }
   D=D->right;
   D->left->right=NULL;
   D->left=NULL;
}

void deleteend(dnode* D)
{
  if(D->right==NULL)
     {
        D=NULL;
        return;
      }
  while(D->right->right!=NULL)
  {
     D=D->right;
  }
  D->right->left=NULL;
  D->right=NULL;
}

void deletespecific(dnode* &D,int k)
{
  if(D->data==k)
  {
   deletefront(D);
   return;
  }
  dnode* temp=D;
   while((temp->right)->data!=k)
    {
      temp=temp->right;
    }
    if(temp->right->right==NULL)
    {
        deleteend(D);
        return;
    }
    temp->right->left==NULL;
    temp->right->right->left=temp;
    temp->right= temp->right->right;
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
     deletespecific(D,3);
     print(D);
    return 0;
}