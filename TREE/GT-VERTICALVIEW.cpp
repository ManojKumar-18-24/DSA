#include<iostream>
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

void create(tree* &t,string s)
{
  static int i=0;
  if(s[i]!='.')
  {
    t=new tree(s[i]);i++;
    create(t->fc,s);i++;
    create(t->ns,s);
  }
}

void verticalprint(tree* t,int level=0)
{
  if(t!=NULL)
  {  
    for(int j=0;j<3*level;j++)cout<<"*";
    cout<<t->data<<endl;
    verticalprint(t->fc,level+1);
    verticalprint(t->ns,level);
  }
}

int main()
{
  tree* t;
  string s="ABF.G..C.DHK.L..I.T..E...";
  create(t,s);
  verticalprint(t);
  return 0;
}