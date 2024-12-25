#include<iostream>
#include<vector>
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

void store(tree* t,vector<int> &v)
{
  if(t==NULL);
  else
  {
    store(t->lc,v);
    v.push_back(t->data);
    store(t->rc,v);
  }
}

void createbtree(tree* &t)
{
  int n;cin>>n;
  if(n!=0)
  {
    t=new tree(n);
    createbtree(t->lc);
    createbtree(t->rc);
  }
}

int main()
{
  tree* t;
  createbtree(t);
  vector<int> v;
  store(t,v);
  int index=0,length=0,max=0;
  for(int i=0;i<v.size()-1;i++)
  {
    if(v[i+1]>v[i])
    {
        length++;
    }
    else
    {
       if(length>max)
       {
        max=length;index=i-length;
       }
       length=0;
    }
  } 
  for(int i=index;i<=index+max;i++)
   cout<<v[i]<<" ";
  return 0;
}