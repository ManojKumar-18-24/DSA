#include<bits/stdc++.h>
using namespace std;

class mtree
{  
    public:
   vector<int> keys;
   vector<mtree*> ptr;
   mtree(int m,int n)
   {
    keys.resize(m-1);
    keys[0]=n;
    ptr.resize(m);
   }
};

void Add(mtree* &head,int m,int key)
{
  if(!head)
  {
    head=new mtree(m,key);
  }
  if(head->keys[0]>key)
  {
    Add(head->ptr[0],m,key);
  }
  else
  {
    Add(head->ptr[1],m,key); 
  }
}

void print(mtree* head,int m)
{
 if(head)
 {
    int count=0;
    for(int i=0;i<head->ptr.size();i++)
    {
        print(head->ptr[i],m);
        if(count==0){cout<<head->keys[0]<<" ";count=1;}
    }
 }
}

int main()
{
 int m;
 cin>>m;
 int n;
 cin>>n;
 mtree* head=new mtree(m,n);
 cin>>n;
 while(n!=0)
 {
   Add(head,m,n);
   cin>>n;
 }
 print(head,m);
return 0;
}