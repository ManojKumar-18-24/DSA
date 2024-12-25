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

void AdjstOddeven( tree* T1, tree* T2)
{
   if(T1 && T2)
   {
    if(T1->data%2==0 && T2->data%2!=0)
    {
        int n=T1->data;
        T1->data=T2->data;
        T2->data=n;
    }
    if(T1->data%2==0 && T2->data%2==0)
    {
        AdjstOddeven(T1,T2->rc);
        AdjstOddeven(T1,T2->lc);
    }
    else if(T1->data%2!=0 && T2->data%2!=0)
    {
        AdjstOddeven(T1->lc,T2);
        AdjstOddeven(T1->rc,T2);
    } 
    else
    {
        AdjstOddeven(T1->lc,T2->rc);
        AdjstOddeven(T1->rc,T2->lc); 
        AdjstOddeven(T1->lc,T2->lc);
        AdjstOddeven(T1->rc,T2->rc);       
    }   
   }
}

void print(tree* t)
{
    if(t)
    {
        cout<<t->data<<" ";
        print(t->lc);
        print(t->rc);
    }
}

int main()
{
 tree* t;
 createbtree(t);
 AdjstOddeven(t->lc,t->rc);
 print(t);
return 0;
}

