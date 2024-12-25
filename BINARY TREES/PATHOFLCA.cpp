#include<iostream>
using namespace std;

class tree
{
    public:
    tree* lc;
    char data;
    tree* rc;
    tree(char n)
    {
        lc=NULL;
        data=n;
        rc=NULL;
    }
};

void createbtree(tree* &t)
{
    char ch;cin>>ch;
    if(ch!='#')
    {
        t=new tree(ch);
        createbtree(t->lc);
        createbtree(t->rc);
    }
}

int find(tree* t,char ch)
{
    int m,n;
  if(t!=NULL)
  {
    if(t->data==ch)return 1;
    m=find(t->lc,ch);
    n=find(t->rc,ch);
    if(m!=0)return m;
    return n;
  }
  return 0;
}

void PathPrint(tree* t,char ch1,char ch2)
{
    int a,b,c,d;
    a=find(t->lc,ch1);
    if(a!=1)b=find(t->rc,ch1);
    c=find(t->lc,ch2);
    if(c!=1)d=find(t->rc,ch2); 
    if(a==1 && c==1)
    {
        cout<<t->data<<" ";
        PathPrint(t->lc,ch1,ch2);
    }  
    else if(b==1 && d==1)
    {
        cout<<t->data<<" ";
        PathPrint(t->rc,ch1,ch2);       
    } 
    else if((a==1 && d==1) || (b==1 && c==1))
    {
      cout<<t->data<<" ";
    }
}

int main()
{
    tree* t;
    createbtree(t);
    char ch1,ch2;
    cin>>ch1>>ch2;
    PathPrint(t,ch1,ch2);
    return 0;
}