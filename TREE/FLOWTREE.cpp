#include<iostream>
#include<vector>
using namespace std;

class tree
{
    public:
    tree* fc;
    char data;
    tree* ns;
    tree(char n)
    {
        fc=NULL;
        data=n;
        ns=NULL;
    }
};

void create(tree* &t)
{
  char ch;cin>>ch;
  if(ch!='.')
  {
    t=new tree(ch);
    create(t->fc);
    create(t->ns);
  }
}

int FindLeaves(tree* t)
{
  if(t!=NULL)
  {
    return (1+FindLeaves(t->fc)+FindLeaves(t->ns));
  }
 return 0;
}

bool Present(tree* f,vector<tree*> v)
{
    for(int i=0;i<v.size();i++)
    {
        if(f==v[i])return false;
    }
    return true;
}

tree* PushtoFind(tree* t,vector<tree*> v)
{
    tree* f=NULL;int max=-1;
  while(t)
  { 
    int n=FindLeaves(t->fc);
    if(n>max && Present(t,v))
    {
        f=t;
        max=n;
    }
    t=t->ns;
  }
  return f;
}

int MinimumPasses(vector<tree*> &v,int iteration=0)
{
    int m=v.size();int count=0;
   for(int i=0;i<m;i++)
   {
      tree* g=PushtoFind(v[i]->fc,v);
      if(g!=NULL)
      {
        v.push_back(g);count++;
      }
   }
   if(count==0)return iteration;
   return MinimumPasses(v,iteration+1); 
}

int main()
{
    tree* t;
    create(t);
    vector<tree*> v;
    v.push_back(t);
    cout<<MinimumPasses(v);
    return 0;
}