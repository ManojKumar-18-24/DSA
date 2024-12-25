#include<iostream>
#include<unordered_set>
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

void print(tree*  t)
{
 if(t!=NULL)
 {
  print(t->rc);
  print(t->lc);
  cout<<t->data<<" ";
 }
}

void FindCommon(tree* t1,tree* t2,unordered_set<int> &s)
{
    if(t1!=NULL && t2!=NULL)
    {
        if(t1->data==t2->data)
        {
            s.insert(t2->data);
            FindCommon(t1->lc,t2->lc,s);
            FindCommon(t1->rc,t2->rc,s);
        }
        else if(t1->data>t2->data)
        {
            FindCommon(t1->lc,t2,s);
            FindCommon(t1,t2->rc,s);
        }
        else
        {
            FindCommon(t1->rc,t2,s);
           FindCommon(t1,t2->lc,s);            
        }
    }
}

int main()
{
  int n;cin>>n;
  tree* t1=new tree(n);
  cin>>n;
  while(n!=-1)
  {
     create(t1,n);
     cin>>n;
  };
  cin>>n;
  tree* t2=new tree(n);
  cin>>n;
  while(n!=-1)
  {
     create(t2,n);
     cin>>n;
  };
  unordered_set<int> s;
  FindCommon(t1,t2,s);
  auto it=s.begin();
  for(it=s.begin();it!=s.end();++it)
  {
    cout<<(*it)<<" ";
  }
  return 0;
}