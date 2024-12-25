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

int find(char ch,string out)
{
    int i=0;
    while(out[i]!=ch)
    {
        i++;
    }
    return i;
}

void createbtree(tree* &t,string pre,string out,int start,int end)
{
  static int header=0;

    t=new tree(pre[header]);
    int p=find(pre[header],out);
    header++;
 if( p+1<=end)     createbtree(t->lc,pre,out,p+1,end);
 if(start<=p-1)   createbtree(t->rc,pre,out,start,p-1);

}

void inprint(tree* t)
{
    if(t==NULL)
    {
        return;
    }
    else
    {
      inprint(t->lc);
      cout<<t->data;
      inprint(t->rc);
    }
}

int main()
{
    tree* t=NULL;
    string pre,out;
    cin>>pre;
    cin>>out;
    pre.erase(pre.length()-1,1);
    out.erase(out.length()-1,1);
    createbtree(t,pre,out,0,pre.length()-1);
    inprint(t);
    return 0;
}