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

void createbtree(tree* &t)
{
    int ch;cin>>ch;
    if(ch!=0)
    {
        t=new tree(ch);
        createbtree(t->lc);
        createbtree(t->rc);
    }
}

int level(tree* t,int k,int l=0)
{
  if(t==NULL)return 0;
  else
  {
    if(t->data==k)return l;
    int n=level(t->lc,k,l+1);
    int m=level(t->rc,k,l+1);
    if(m!=0)return m;
    return n;
  }
  return 0;
}

int find(tree* t,int k)
{
  if(t==NULL)return 0;
  else
  {
    if(t->data==k)return 1;
    int n=find(t->lc,k);
    int m=find(t->rc,k);
    if(m!=0)return m;
    return n;
  }
  return 0;
}

int find_distance(tree* t,int k1,int k2)
{
    int a=find(t->lc,k1);
    int b=find(t->lc,k2);
    int c=find(t->rc,k1);
    int d=find(t->rc,k2);
    if(t->data==k1)
    {
        if(b==1)
        {
            return level(t->lc,k2)+1;
        }
        return level(t->rc,k2)+1;
    }
    else if(t->data==k2)
    {
        if(a==1)
        {
            return level(t->lc,k1)+1;
        }
        return level(t->rc,k1)+1;
    }
    else if(a==1 && d==1)
    {
        return(level(t->lc,k1)+level(t->rc,k2)+2);
    }
    else if(b==1 && c==1)
    {
        return(level(t->lc,k2)+level(t->rc,k1)+2); 
    }
    else if (a==1 && b==1)
    {
        return find_distance(t->lc,k1,k2);
    }
    else
    return find_distance(t->rc,k1,k2);
}

int main()
{
 tree* t;
 createbtree(t);
 int k1,k2;
 cin>>k1>>k2;
 while(k1!=-1 && k2!=-1)
 {
 cout<<find_distance(t,k1,k2);
 cin>>k1>>k2;
 }
return 0;
}