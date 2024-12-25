#include<iostream>
#include<map>
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

void verticalorder(tree* t,map<int,vector<int>> &m,int x=0)
{
  if(t==NULL);
  else
  {
     m[x].push_back(t->data);
    verticalorder(t->lc,m,x-1);
    verticalorder(t->rc,m,x+1);
  }
}

int main()
{
    tree* t=NULL;
    createbtree(t);
    map<int,vector<int>> m;
    verticalorder(t,m);
    auto it=m.begin();
    for(it=m.begin();it!=m.end();++it)
    {
        auto v=it->second;
        int i=0;int sum=0;
        while(i<v.size())
        {
            cout<<v[i]<<" ";sum+=v[i];++i;
        }
        cout<<sum<<endl;
    }
    return 0;
}