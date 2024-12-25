#include<iostream>
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
    rc=NULL;
    data=n;
 }
};

class dnode
{
 public:
 dnode* left;
 int data;
 dnode* right;
 dnode(int n)
 {
    left=NULL;
    right=NULL;
    data=n;
 }
};

void addend(dnode* &D,int n)
{
    if(D==NULL)
    {
        D=new dnode(n);return;
    }
    dnode* temp=D;
    while(temp->right!=NULL)temp=temp->right;
    dnode* g=new dnode(n);
    temp->right=g;
    g->left=temp;
}

void create(tree* &t,int n)
{
    if(t==NULL)
    {
        t=new tree(n);
    }
    else if(n>t->data)
    {
        create(t->rc,n);
    }
    else
    {
        create(t->lc,n);
    }
}

void travel(tree* t,dnode* &D)
{
    if(t==NULL);
    else
    {
        travel(t->lc,D);
        addend(D,t->data);
        travel(t->rc,D);
    }
}

int main()
{
    int n;cin>>n;
    dnode* D=NULL;
    tree* t1=new tree(n);
    cin>>n;
    while(n!=-1) {     create(t1,n);cin>>n; }
    cin>>n;
    tree* t2=new tree(n);
    cin>>n;
   while(n!=-1) {     create(t2,n);cin>>n; }
    int sum;cin>>sum;
    travel(t1,D);addend(D,-1);travel(t2,D);
   dnode* k=D;
    while(k->right!=NULL)k=k->right;
    while(D->data!=-1 && k->data!=-1)
    {
        if(D->data+k->data==sum)
        {
            cout<<D->data<<" "<<k->data<<endl;
            D=D->right;k=k->left;
        }
        else if(D->data+k->data>sum)
        {
            k=k->left;
        }
        else 
        {
            D=D->right;
        }
    }
    return 0;
}