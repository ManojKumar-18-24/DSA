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

void psum(tree* t1,tree* t2,int sum)
{
    if(t1!=NULL && t2!=NULL)
    {
      if(t1->data+t2->data>sum)
      {
        psum(t1->lc,t2,sum);
        psum(t1,t2->lc,sum);
      }
     else if(t1->data+t2->data==sum)
     {
        cout<<t1->data<<" "<<t2->data<<endl;
        psum(t1->lc,t2->rc,sum);
        psum(t1->rc,t2->lc,sum);        
     }
     else
     {
        psum(t1->rc,t2,sum);
        psum(t1,t2->rc,sum);        
     }
    }
}

int main()
{
  int n;cin>>n;
  tree* t1=new tree(n);
  cin>>n;
  while(n!=-1)
  {
     create(t1,n);
     cin>>n;
  };
  cin>>n;
  tree* t2=new tree(n);
  cin>>n;
  while(n!=-1)
  {
     create(t2,n);
     cin>>n;
  }; int sum;
  cin>>sum;
  psum(t1,t2,sum);
  return 0;
}