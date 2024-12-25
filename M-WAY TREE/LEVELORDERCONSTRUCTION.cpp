#include<bits/stdc++.h>
using namespace std;

class mtree
{  
    public:
    int count=0;
   vector<int> keys={-1};
   vector<mtree*> ptr;
   mtree(int m,int n)
   {
    keys.resize(m-1);
    for(int i=0;i<keys.size();i++)keys[i]=-1;
    keys[0]=n;
    count++;
    ptr.resize(m);
   }
};

mtree* Findparent(mtree* head,mtree* parent)
{
    if(!head)return parent;
    else
    {
        
    }
}

void Add(mtree* &head,int m,int key)
{
   queue<mtree*> Q;
   Q.push(head);
   mtree* parent=NULL;
   while(true)
   {
     mtree* t=Q.front();
     Q.pop();
     if(!t)
     {
        t=new mtree(m,key);return;
     }
     for(int i=0;i<m-1;i++)
     {
        if(t->keys[i]==-1)
        {
            t->keys[i]=key;
            return;
        }
     }
     for(int i=0;i<m;i++)
     {
        Q.push(t->ptr[i]);
     }
   }
}

int c=1;

void print(mtree* head,int level,int l=0)
{
 if(head)
 {
    int count=0;
    for(int i=0;i<head->ptr.size();i++)
    {
      print(head->ptr[i],level,l+1);
      if(i<head->ptr.size()-1 && head->keys[i]!=-1 && l==level){c++;cout<<head->keys[i]<<" ";} 
    }
 }
}

int main()
{
 int m;
 cin>>m;
 int n;cin>>n;
 mtree* head=new mtree(m,n);
 cin>>n;
 while(n!=-1)
 {
   Add(head,m,n);
   cin>>n;
 }
 int i=0;
 while(c>0)
 {
  c=0;
  print(head,i);
  i++;
  if(c>0)cout<<"/"<<endl;
 }
return 0;
}