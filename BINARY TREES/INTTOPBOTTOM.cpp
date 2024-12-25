#include<iostream>
#include<map>
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

void topview(tree* t,map<int,int>& m,int x=0)
{
   static int xleftrange=0,xrightrange=0;
   if(t==NULL);
   else
   {
      if(x<xleftrange)
      {
        xleftrange=x;m[x]=t->data;
      }
      else if(x>xrightrange)
      {
        xrightrange=x;m[x]=t->data;
      }
      topview(t->lc,m,x-1);
      topview(t->rc,m,x+1);
   }       
}

int find(map<int,int> m,int x)
{
   auto it=m.begin();
   for(it=m.begin();it!=m.end();++it)
   {
     if(it->first==x)
      return it->second;
   }
   return 0;
}

void bottomview(tree* t,map<int,int> &m,map<int,int> &m1,int x=0,int y=0)
{    static int yrange=0;
    if(t==NULL);
    else
    {
        if(find(m1,x)==0 ||find(m1,x)<=y)
        {
            m[x]=t->data;m1[x]=y;
        }
        bottomview(t->lc,m,m1,x-1,y+1);
        bottomview(t->rc,m,m1,x+1,y+1);
    }
}

int main()
{   tree* t=NULL;
    createbtree(t);map<int,int> m;map<int,int> m1;
    topview(t,m);
    auto it=m.begin();m[0]=t->data;
    for(it=m.begin();it!=m.end();++it)
    {
       cout<<it->second<<" ";
    }
    m.clear();cout<<endl;
    bottomview(t,m,m1);
    for(it=m.begin();it!=m.end();++it)
    {
       cout<<it->second<<" ";
    }
    return 0;
}

