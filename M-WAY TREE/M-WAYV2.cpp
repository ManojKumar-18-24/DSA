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

void Add(mtree* &head,int m,int key)
{
  if(!head)
  {
    head=new mtree(m,key);
  }
  else
  {
    if(head->count<m-1)
    {
      for(int i=0;i<head->keys.size();i++)
      {
        if(key<head->keys[i] || head->keys[i]==-1)
        {
           for(int j=head->keys.size()-1;j>i;j--)
           {
             head->keys[j]=head->keys[j-1];
           }
           head->keys[i]=key;
           head->count++;
           return;
        }
      }
    }
    else
    {
           for(int j=0;j<head->keys.size();j++)
           {
             if(key<head->keys[j]){Add(head->ptr[j],m,key);return;}
           } 
           if(key>head->keys[m-2]) Add(head->ptr[m-1],m,key);    
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
     // if(i<head->ptr.size()-1 && head->keys[i]!=-1)cout<<head->keys[i]<<" ";
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
 while(n!=0)
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