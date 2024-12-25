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

int tag=0;

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

void findATDT(tree* t,vector<vector<int>> &v)
{
    static int i=1,nodecount=1;
    if(t==NULL);
    else
    { 
        int p=nodecount;v.resize(p+1);v[p].push_back(t->data);
        v[p].push_back(i);i++;nodecount++;
        findATDT(t->lc,v);
        findATDT(t->rc,v);
        v[p].push_back(i);i++;
    }
}

void ancestor(tree* t,int parent,int son)
{
  if(t==NULL)return;
  if(tag==0)
  {
    if(t->data==parent)
    {
        tag++;ancestor(t,parent,son);
    }
    else
    {
      if(tag==0)  ancestor(t->lc,parent,son);
      if(tag==0)  ancestor(t->rc,parent,son);
    }
  }
  else
  {
    if(t->data==son)
    {
        cout<<1<<" ";tag=0;
    }
    else
    {
        ancestor(t->lc,parent,son);
        ancestor(t->rc,parent,son);       
    }
  }
}

int main()
{
    tree* t=NULL;
    createbtree(t);
    vector<vector<int>> v;
    findATDT(t,v);
    for(int i=0;i<v.size();i++){    for(int j=0;j<v[i].size();j++)    {    cout<<v[i][j]<<" ";}  cout<<endl;}
    int parent,b,son;
    cin>>parent;
    while(parent!=0)
    {
        cin>>b>>son;
        if(b==-1)
        {
            ancestor(t,parent,son);
            if(tag>0)cout<<0<<" ";tag=0;
        }
        else
        {
            ancestor(t,son,parent);if(tag>0)cout<<0<<" ";tag=0;
        }
        cin>>parent;
    }
    return 0;
}