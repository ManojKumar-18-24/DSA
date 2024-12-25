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

int c,d,e=0,f=0;

void findlevel(tree* t,int key,int parent,int p,int i=0)
{
    if(t==NULL);
    else if(t->data==key )
    {
        if(p%2==0)
        {
            c=i;e=parent;
        }
        else 
        {d=i;f=parent;}
    }
    else
    {
        findlevel(t->lc,key,t->data,p,i+1);
        findlevel(t->rc,key,t->data,p,i+1);
    }
}

void createbtree(tree* &t,int a[],int n)
{
    static int i=0;
    if(i==n)return;
    else  if(a[i]!=0)
    {
        t=new tree(a[i]);i++;
        createbtree(t->lc,a,n);i++;
        createbtree(t->rc,a,n);
    }
}

int main() {
    
    tree* t;
    int a[]={6,3,7,0,0,8,0,0,5,1,0,0,3,0,0};createbtree(t,a,15);
    int g[]={7,1,3,5,7,5};
    int i=0;
    while(i<6) 
    { 
       findlevel(t,g[i],0,i);findlevel(t,g[i+1],0,i+1);
      if(c==d && e!=f)
       {
          cout<<1<<endl;
       }
      else cout<<0<<endl;i+=2;
    }
    return 0;
}