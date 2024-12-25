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

tree* findprevnode(tree* t,char ch,tree* parent)
{
   if(t==NULL)return NULL;
   else if( t->data==ch)
   {
    return parent;
   }
   else
   {
    tree* left=findprevnode(t->lc,ch,t);
    tree* right=findprevnode(t->rc,ch,t);
    if(left!=NULL)return left;
    return right;
   }
}

int maxDepth(tree* t,int level=0)
{
          int n,m;
        if(t==NULL)return level;
        else
        {
             n=maxDepth(t->lc,level+1);
             m=maxDepth(t->rc,level+1);
        }
        if(m>n)return m;
        return n;  
}

char finddeepnode(tree* t,int depth,int level=0)
{
    char ch1,ch2;
    if(t==NULL)return '0';
    else if(level==depth)
    {
      return t->data;
    }
    else
    {
      ch1=finddeepnode(t->lc,depth,level+1);
      ch2=finddeepnode(t->rc,depth,level+1);
    }
    if(ch1!='0')return ch1;
    return ch2;
}

void preprint(tree* t)
{
  if(t!=NULL)
  {
    cout<<t->data;
    preprint(t->lc);
    preprint(t->rc);
  }
}

int main()
{
    tree* t=NULL;
    createbtree(t);tree* parent=t;int i=0;
    while(i<2)
    {
    char ch;cin>>ch;
    if(ch!=t->data)
    {
      tree* g=findprevnode(t,ch,parent);
      int n=0;
      if(g->lc->data==ch)
      {
         n=maxDepth(g->lc);
        tree* m=findprevnode(t,finddeepnode(g->lc,n-1),parent);
        if(m->lc!=NULL)
          {
            m->lc->lc=g->lc->lc;
            m->lc->rc=g->lc->rc;g->lc=m->lc;
            m->lc=NULL;
          }
        else
        {
          m->rc->lc=g->lc->lc;
          m->rc->rc=g->lc->rc;g->lc=m->rc;
          m->rc=NULL;
        }
      }
      else
      {
         n=maxDepth(g->rc);
        tree* m=findprevnode(t,finddeepnode(g->rc,n-1),parent);
        if(m->lc!=NULL)
          {
            m->lc->lc=g->rc->lc;
            m->lc->rc=g->rc->rc;g->rc=m->lc;
            m->lc=NULL;
          }
        else
        {
          m->rc->lc=g->rc->lc;
          m->rc->rc=g->rc->rc;g->rc=m->rc;
          m->rc=NULL;
        }       
      }     
    }
    else
    { int n;
      n=maxDepth(t);
      tree* m=findprevnode(t,finddeepnode(t,n-1),parent);
        if(m->lc!=NULL)
          {
            m->lc->lc=t->lc;
            m->lc->rc=t->rc;
           t=m->lc; m->lc=NULL;
          }
        else
        {
          m->rc->lc=t->lc;
          m->rc->rc=t->rc;
          t=m->rc;m->rc=NULL;
        }    
    }
      preprint(t); cout<<endl; 
    i++;
    }
    return 0;
}