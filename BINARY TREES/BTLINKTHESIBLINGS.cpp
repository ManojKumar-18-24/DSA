#include<iostream>
using namespace std;

class tree
{
    public:
    tree* lc;
    char data;
    tree* ns;
    tree* rc;
    tree(char n)
    {
        lc=NULL;
        data=n;
        rc=NULL;
        ns=NULL;
    }
};

void createbtree(tree* &t)
{
    char ch;cin>>ch;
    if(ch!='#')
    {
        t=new tree(ch);
        createbtree(t->lc);
        createbtree(t->rc);
    }
}

tree* FindNextSibling(tree* t,int level,int x,char ch,int &p,int l1=0,int x1=0)
{
   if(t==NULL)
   {
     return NULL;
   }
   else if(level==l1 && x1>=x)
   {
     if(t->data!=ch && p==0)return NULL;
     if(t->data==ch){p++;return NULL;}
     return t;
   }
   else
   {
    tree* f=FindNextSibling(t->lc,level,x,ch,p,l1+1,x1-1);
    tree* g=FindNextSibling(t->rc,level,x,ch,p,l1+1,x1+1);
    if(f!=NULL)
    {
        return f;
    }
    return g;
   }
}

void AttachNextSiblings(tree* &t,int level=0,int x=0)
{
    static tree* temp=t;
   if(t==NULL)return ;
   else
   {
      int p=0;
      tree* d=FindNextSibling(temp,level,x,t->data,p);
      t->ns=d;
      AttachNextSiblings(t->lc,level+1,x-1);
      AttachNextSiblings(t->rc,level+1,x+1);
   }
}

void print(tree* t,int level=0)
{
    static int p=-1;
  if(t!=NULL)
  {
     if(level>p)
     {
        tree* temp=t;
        while(temp)
        {
            cout<<temp->data<<" ";
            if(temp->data=='M')cout<<"N ";
            temp=temp->ns;
        }
        cout<<"/ ";
        p++;
     }
    print(t->lc,level+1);
    print(t->rc,level+1);
  }
}

int main()
{
    tree* t;
    createbtree(t);
    AttachNextSiblings(t);
    print(t);
    return 0;
}


