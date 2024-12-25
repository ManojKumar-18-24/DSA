#include<iostream>
#include<vector>
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

int find(vector<int> v,int end,int start)
{
    int min=v[start],i=start;
    while(start<=end)
    {
        if(v[start]<min)
        {
           min=v[start],i=start; 
        }
        start++;
    }
    return i;
}

void create(tree* &t,vector<int> v,int end,int start=0)
{
  int i=find(v,end,start);
  t=new tree(v[i]);
  if(start<=i-1)create(t->lc,v,i-1,start);
  if(i+1<=end)create(t->rc,v,end,i+1);
}

void print(tree* t)
{
 if(t!=NULL)
 {
    cout<<t->data<<" ";
    print(t->lc);
    print(t->rc);
 }
}

int main()
{
 vector<int> v;
 int n;cin>>n;
 while(n!=-1)
 {
    v.push_back(n);
    cin>>n;
 }
 tree* t=NULL;
 create(t,v,v.size()-1);
 print(t);
 return 0;
}