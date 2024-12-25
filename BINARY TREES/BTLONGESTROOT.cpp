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

void FindLongestPath(tree* t,vector<int> &v1,vector<int> &v2,int level=0)
{
    if(t==NULL)
    {
       if(v1.size()>v2.size())
       {
         v2.resize(v1.size());
        for(int i=0;i<v1.size();i++)
        {
            v2[i]=v1[i];
        }
       }
    }
    else
    {
        v1.resize(level+1);
        v1[level]=t->data;
        FindLongestPath(t->lc,v1,v2,level+1);
        FindLongestPath(t->rc,v1,v2,level+1);
    }
}

int main()
{
    tree* t;
    createbtree(t);
    vector<int> v1,v2;
    FindLongestPath(t,v1,v2);
    cout<<v2.size()-1<<endl;
    for(int i=0;i<v2.size();i++)
    {
        cout<<v2[i]<<" ";
    }
    return 0;
}