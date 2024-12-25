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

void printminmax(tree* t,int min=0,int max=99999)
{
    if(t!=NULL)
    {
        int a=min,b=max;
        printminmax(t->lc,min,t->data-1);
        printminmax(t->rc,t->data+1,max);
        cout<<t->data<<" "<<a<<" "<<b<<endl;  
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
  printminmax(t);
  return 0;
}
          