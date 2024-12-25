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

int find(char ch,string in)
{
    int i=0;
    while(in[i]!=ch)
    {
        i++;
    }
    return i;
}

void createbtree(tree* &t,string pre,string in,int start,int end)
{
    static int header=0;
    t=new tree(pre[header]);
    int p=find(pre[header],in);
    header++;
 if(start<=p-1)   createbtree(t->lc,pre,in,start,p-1);
 if(p+1<=end)     createbtree(t->rc,pre,in,p+1,end);
}

void serprint(tree* t)
{
    if(t==NULL)cout<<"#";
    else
    {
      cout<<t->data;
      serprint(t->lc);
      serprint(t->rc);
    }
}

int main()
{
    tree* t=NULL;
    string pre,in;
    cin>>pre;
    cin>>in;
    pre.erase(pre.length()-1,1);
    in.erase(in.length()-1,1);
    createbtree(t,pre,in,0,pre.length()-1);
    serprint(t);
    return 0;
}