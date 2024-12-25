#include<iostream>
using namespace std;

class dnode
{  
  public:
  int data;
  dnode* left;
  dnode* right;
  dnode(int num1)
  { 
    data=num1;
    right=NULL;
    left=NULL;
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

void print1(dnode* D,dnode* S)
{
  while(1)
  {
    cout<<D->data<<" "<<S->data<<" ";
    if(D==S || D->right==S) break;
    D=D->right;S=S->left;
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
     dnode* SP=D;dnode* FP=D;
     while(FP->right)
     {
        SP=SP->right;
        FP=(FP->right)->right;
     }
     print1(D,SP->left);
     cout<<SP->data<<" ";
     while(FP!=SP)
     {
        cout<<FP->data<<" ";
        FP=FP->left;
     }
     return 0;
}