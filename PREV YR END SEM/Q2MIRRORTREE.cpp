#include<iostream>
using namespace std;
/*                     YOU CAN DO                                      */
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

int main()
{
    
    return 0;
}