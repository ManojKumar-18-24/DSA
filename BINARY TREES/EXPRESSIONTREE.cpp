#include<iostream>
using namespace std;

class tree
{
    public:
    tree* lc;
    char data;
    tree* rc;
    tree(char n)
    {
        lc=NULL;
        data=n;
        rc=NULL;
    }
};

void createetree(tree* &t,string s)
{
    static int i=0;
    if(s[i]>'0')
     {
        t=new tree(s[i]);
     }
    else
    {
        t=new tree(s[i]);i++;
        createetree(t->lc,s);i++;
        createetree(t->rc,s);
    }
}

int eval(tree* t)
{
  if(t!=NULL)
  {
    if(t->data>='0')
       return (t->data-'0');
    else
    {
        switch(t->data)
        {
            case '+':return eval(t->lc)+eval(t->rc);
            case '-':return eval(t->lc)-eval(t->rc);
            case '*':return eval(t->lc)*eval(t->rc);
            case '/':return eval(t->lc)/eval(t->rc);
        }
    }
  }
}

int main()
{
    tree* t=NULL;
    string str;
    cin>>str;
    createetree(t,str);
   cout<<eval(t);
    return 0;
}