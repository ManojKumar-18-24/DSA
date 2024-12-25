#include<iostream>
#include<vector>
using namespace std;

class tree
{
    public:
    tree* lc;
    int data;
    tree* rc;
    tree(char n)
    {
        lc=NULL;
        data=n;
        rc=NULL;
    }
};

int find(int ch,vector<int> post)
{
    int i=0;
    while(post[i]!=ch)
    {
        i++;
    }
    return i;
}

void createbtree(tree* &t,vector<int> pre,vector<int> post,int start,int end)
{
    static int header=0;
    t=new tree(pre[header]);
   if(header+1<pre.size())
   { int p=find(pre[header+1],post);
    header++;
    if(start<=p && p<end)createbtree(t->lc,pre,post,start,p);
    if(p+1<end)  createbtree(t->rc,pre,post,p+1,end-1);
   }
}

void serprint(tree* t)
{
    if(t==NULL);
    else
    {
      
      serprint(t->rc);
      serprint(t->lc);
          cout<<t->data<<" ";
    }
}

int main()
{
    tree* t=NULL;
    vector<int> pre={1,2,4,6,5,3,7,8,9,10,11,13,12},post={6,5,4,7,8,3,2,13,11,10,12,9,1};
    createbtree(t,pre,post,0,pre.size()-1);
    serprint(t);
    return 0;
}

