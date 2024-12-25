#include<bits/stdc++.h>
using namespace std;

class tree
{
    public:
    tree* fc;
    int data;
    tree* ns;
    tree(int n)
    {
        fc=NULL;
        data=n;
        ns=NULL;
    }
};

int k=0;

void create(tree* &t,int a[])
{
  static int i=0;
  if(a[i]!=0)
  {
    t=new tree(a[i]);i++;
    create(t->fc,a);i++;
    create(t->ns,a);
  }
}

void verticalprint(tree* t,vector<int> &m,int source,int target,int level=0)
{
  if(t!=NULL)
  {  
    if(t->data==source)k++;
    if(k>0 && k<2)
     {
        m.resize(level+1);
        m[level]=t->data;
     }
    if(t->data==target)k++;
    verticalprint(t->fc,m,source,target,level+1);
    verticalprint(t->ns,m,source,target,level);
  }
}

int main()
{
  tree* t;
  vector<int> m;
  int a[]={1,2,3,4,5,6,7,0,0,8,9,0,0,0,0,10,11,12,0,0,14,15,16,0,0,0,17,18,0,0,0,0,0,0};
  create(t,a);
  int source,target;
  cin>>source>>target;
  while(source!=-1 && target!=-1)
  {
  verticalprint(t,m,source,target);
  for(int i=0;i<m.size();i++)if(m[i]!=0)cout<<m[i]<<" ";
  cout<<endl;k=0;
  m.erase(m.begin(),m.end());
  cin>>source>>target;
  }
  return 0;
}