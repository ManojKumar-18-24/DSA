#include<iostream>
using namespace std;

class dnode
{
    public:
    dnode* left=NULL;
    int data;
    dnode* right;
    dnode(int n)
    {
        left=NULL;
        data=n;
        right=NULL;
    }
};

class tree
{
    public:
    tree* lc;
    char key;
    dnode* dlptr;
    tree* rc;
    tree(char n)
    {
        lc=NULL;
        key=n;
        dlptr=NULL;
        rc=NULL;
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

tree* inputfind(tree * t,char k)
{
    if(t==NULL)return NULL;
    else if(t->key>k)
     return inputfind(t->lc,k);
    else if(t->key<k)
    {
        return inputfind(t->rc,k);
    }
    else
    return t;
}

void create(tree* &t,char k,int x)
{
    if(t==NULL)
    {
        t=new tree(k);
        addend(t->dlptr,x);
    }
    else if(t->key>k)
    {
        create(t->lc,k,x);
    }
    else 
    create(t->rc,k,x);
}

void set(tree* &t,char k,int x)
{
    if(t==NULL);
    else if(t->key>k) set(t->lc,k,x);
    else if(t->key<k) set(t->rc,k,x);
    else addend(t->dlptr,x);
}

void print(tree* t,char k)
{
    if(t==NULL)cout<<-1;
    else if(t->key>k) print(t->lc,k);
    else if(t->key<k) print(t->rc,k);
    else
    {
        while(t->dlptr!=NULL)
        {
            cout<<t->dlptr->data<<" ";
            t->dlptr=t->dlptr->right;
        }
    }
}

int main()
{
    tree* t=NULL;char key; int data;
    cin>>key>>data;
    create(t,key,data);
    cin>>key>>data;
    while(key!='#')
    {
        if(inputfind(t,key))
        {
          set(t,key,data);
        }
        else create(t,key,data);
        cin>>key>>data;    
    }
    cin>>key;
    print(t,key);
    return 0;
}