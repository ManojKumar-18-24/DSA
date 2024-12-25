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

tree* btptr=NULL;

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

void print(tree* t)
{
    if(t==NULL){cout<<'.';return;}
    cout<<t->data;
    print(t->fc);
    print(t->ns);
}

int Findchildren(tree* t)
{
 t=t->fc;int count=0;
 while(t)
 {
  count++;t=t->ns;
 }
 return count;
}

void GTTOBTS(tree* t)
{
   if(t!=NULL)
   {
     
   }
}

int main()
{
 tree* t;
 create(t);

return 0;
}
