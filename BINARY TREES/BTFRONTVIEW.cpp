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

void frontview(tree* t1,tree* t2,tree* t3)
{
   if(t1==NULL && t2==NULL && t3==NULL);
   else
   {
     if(t3!=NULL) { cout<<t3->data<<" "; }
     else if(t2!=NULL)cout<<t2->data<<" ";
     else cout<<t1->data<<" ";
      if(t1!=NULL && t2!=NULL && t3!=NULL)
       {
        frontview(t1->lc,t2->lc,t3->lc);
        frontview(t1->rc,t2->rc,t3->rc);
        }
      else if(t1!=NULL && t2!=NULL && t3==NULL)
        {
        frontview(t1->lc,t2->lc,NULL);
        frontview(t1->rc,t2->rc,NULL);       
        }
      else  if(t1!=NULL && t2==NULL && t3!=NULL)
        {
        frontview(t1->lc,NULL,t3->lc);
        frontview(t1->rc,NULL,t3->rc);
        }
      else if(t1==NULL && t2!=NULL && t3!=NULL)
       {
        frontview(NULL,t2->lc,t3->lc);
        frontview(NULL,t2->rc,t3->rc);
       }
      else if(t1==NULL && t2==NULL && t3!=NULL)
       {
        frontview(NULL,NULL,t3->lc);
        frontview(NULL,NULL,t3->rc);
       }
      else if(t1==NULL && t2!=NULL && t3==NULL)
       { 
        frontview(NULL,t2->lc,NULL);
        frontview(NULL,t2->rc,NULL);
       }
      else if(t1!=NULL && t2==NULL && t3==NULL)
       {
        frontview(t1->lc,NULL,NULL);
        frontview(t1->rc,NULL,NULL);
       }
   }
}

int main()
{
    tree* t1;tree* t2;tree* t3;
    createbtree(t1);createbtree(t2);createbtree(t3);
    frontview(t1,t2,t3);
    return 0;
}









