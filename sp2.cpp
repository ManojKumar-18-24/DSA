#include<bits/stdc++.h>
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

void create(tree* &t,int k)
{
   if(t==NULL)
   {
    t=new tree(k);
   }
   else if(t->data>k)
   {
     create(t->lc,k);
   }
   else 
   {
    create(t->rc,k);
   }
}

void don(tree* t,vector<tree*> &v,int j)
{
   cout<<t->data<<" ";
   if(t->lc!=NULL)v.push_back(t->lc);
   if(t->rc!=NULL)v.push_back(t->rc); 
   //if(j>=0)v[j]=NULL; 
   for(int i=0;i<v.size();i++)
   {
     if(v[i]!=NULL)don(v[i],v,i);
   }
}

int main()
{
 tree* t=NULL;
 int n;
 cin>>n;
 while(n!=-1)
 {
    create(t,n);
    cin>>n;
 }
 vector<tree*> v;
 don(t,v,-1);
return 0;
}