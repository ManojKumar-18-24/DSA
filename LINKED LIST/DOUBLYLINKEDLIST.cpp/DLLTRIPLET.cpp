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

dnode* addend(dnode* D,int n)
{
  while(D->right!=NULL)
  {
   D=D->right;
  }
  dnode* g=new dnode(n);
  D->right=g;
  g->left=D;
  return g;
}

void printtriplets(dnode* x,dnode* y,dnode* z,int s )
{
  dnode* temp=z;
  while(x->right!=NULL)
  {
    if(2*(x->data)+y->data+z->data==s)
    {
      if(x->data!=y->data && y->data!=z->data && z->data!=x->data)cout<<x->data<<" "<<y->data<<" "<<z->data<<endl;
      if(y->right==z)
      {
        x=x->right;z=temp;y=z->left;
      }
      else
      {
        z=z->left;
        y=z->left;
      }
    }
    else
    {
      y=y->left;
      if(y==NULL)
      {
        z=z->left;
        if(z->left->left==NULL)
        {
          x=x->right;z=temp;y=z->left;
        }
        else  y=z->left;
      }
    }
  }
}

int main()
{
    int n;cin>>n;
    dnode* D= new dnode(n);
    cin>>n;
    dnode* temp;
    while(n!=-1)
     {
       temp=addend(D,n);
       cin>>n;
     }
     cin>>n;
    printtriplets(D,temp->left,temp,n);
    return 0;
}