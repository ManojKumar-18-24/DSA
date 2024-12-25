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

int Findlevel(tree* t,char ch,int level=0)
{
    if(t!=NULL)
    {
        if(t->data==ch)return level;
        int m=Findlevel(t->fc,ch,level+1);
        int n=Findlevel(t->ns,ch,level);
        if(m!=0)return m;
        return n;
    }
    return 0;
}

tree* FindParent(tree* t,tree* parent,char ch)
{
   if(t!=NULL)
   {
       if(t->data==ch)
       {
        return parent;
       }
       tree* g=FindParent(t->fc,t,ch);
       tree* f=FindParent(t->ns,parent,ch);
       if(g!=NULL)return g;
       return f;
   }
   return t;
}

char u;

void FindCousins(tree* t,int level,char ch,int l=0)
{
    static tree* temp=t;
    static int i=0;
    if(t==NULL)
    {
        ;
    }
    else
    {
        if(level==l && FindParent(temp,temp,t->data)!=FindParent(temp,temp,ch))
        {
          if(i==0)cout<<t->data;u=t->data;i++;
        }
        FindCousins(t->fc,level,ch,l+1);
        FindCousins(t->ns,level,ch,l);
    }
}

int main()
{
  tree* t=NULL;
  create(t);
  char ch;
  cin>>ch;
  vector<char> v;
  FindCousins(t,Findlevel(t,ch),ch);
  cout<<u;
  return 0;
}
