#include<iostream>
#include<vector>
using namespace std;

class tree
{
    public:
    tree* fs;
    int data;
    tree* ns;
    tree(int n)
    {
        fs=NULL;
        data=n;
        ns=NULL;
    }
};

void create(tree* &t)
{
    int i;
    cin>>i;
  if(i!=0)
  {
    t=new tree(i);
    create(t->fs);
    create(t->ns);
  }
}

void travel(vector<vector<int>> &G,tree* t,int level)
{
    if(t)
    {
        if(G.size()<=level)G.push_back(vector<int>());
        G[level].push_back(t->data);
        travel(G,t->fs,level+1);
        travel(G,t->ns,level);
    }
}

void change(vector<vector<int>> &G)
{
    int i,j;
    vector<int> v;
    for(int i=0;i<G.size();i++)
    {
        for(int j=0;j<G[i].size();j++)
        {
            v.push_back(G[i][j]);
        }
    }
     i=0;
   j=v.size()-1;
  vector<int> v1;
  while(i<j)
  {
    while(i<v.size() && v[i]%2==0)i++;
    while(j>=0 && v[j]%2!=0)j--;
    if(i<j)
    {v1.push_back(v[i]);
    v[i]=v[j];
    v[j]=-1;
    i++;j--;
    }
  }
  i=0;
  for(int l=0;l<v.size();l++)
  {
    if(v[l]==-1)
    {
      v[l]=v1[i];i++;
    }
  }
   int l=0;
      for(int i=0;i<G.size();i++)
    {
        for(int j=0;j<G[i].size();j++)
        {
            G[i][j]=v[l];l++;
        }
    }
}

void put(vector<vector<int>> &G,tree* t,int level)
{
    if(t)
    {
        int i;
        for(i=0;i<G[level].size();i++)
        {
            if(G[level][i]!=-1)break;
        }
        t->data=G[level][i];
        G[level][i]=-1;
        put(G,t->fs,level+1);
        put(G,t->ns,level);
    }
}

void print(tree* t)
{
  if(t!=NULL)
  {
    cout<<t->data<<" ";
    print(t->fs);
    print(t->ns);
  }
  else cout<<"0 ";
}

int main()
{
    tree* t;
    create(t);
    vector<vector<int>> G;
    travel(G,t,0);
    change(G);
    put(G,t,0);
    print(t);
    return 0;
}