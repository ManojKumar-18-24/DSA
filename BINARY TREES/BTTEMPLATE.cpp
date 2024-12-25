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

void createbtree(tree* &t)
{
    char ch;cin>>ch;
    if(ch!='#')
    {
        t=new tree(ch);
        createbtree(t->lc);
        createbtree(t->rc);
    }
}
