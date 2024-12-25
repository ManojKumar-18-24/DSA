#include<iostream>
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

struct stack
{
  int size=100;
  tree* elements[100];
  int top=-1;
};

tree* peep(stack &M)
{
    return (M.top==-1)?NULL:M.elements[M.top];
}

tree* pop(stack &M)
{
    return ( M.top==-1)?NULL: M.elements[M.top--];
}

void push(stack &M,tree* x)
{
  if(M.top==M.size-1);
  else
  { 
    M.top++;
    M.elements[M.top]=x;
  }
}

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

void psum(tree* temp1,tree* temp2,stack &M1,stack &M2,int sum)
{
  static int r=0,s=0;
  push(M1,temp1);push(M2,temp2);tree* g=peep(M1)->lc;tree* f=peep(M2)->rc;
    while(M1.top!=-1 && M2.top!=-1)
    {
      while(g!=NULL)
      {
        push(M1,g);//cout<<g->data<<" ";
        g=g->lc;
      }
      while(f!=NULL)
      {
        push(M2,f);//cout<<f->data<<" ";
        f=f->rc;
      }   
      while(M1.top!=-1 && M2.top!=-1)
      {
        g=peep(M1);
        int n=g->data;
        f=peep(M2);
        int m=f->data;
        if(m+n>sum)
        {
          f=pop(M2);if(f->lc!=NULL){push(M2,f->lc);f=f->lc;break;}
        }
        else if(m+n<sum)
        {
          g=pop(M1);if(g->rc!=NULL){push(M1,g->rc);g=g->rc;break;}
        }
        else
        {
          if(r!=m && s!=n)
          {
            cout<<n<<" "<<m<<endl;r=m;s=n;
          }
          f=pop(M2);
          if(f->lc!=NULL)
          {
            push(M2,f->lc);f=f->lc;
            g=pop(M1);
            if(g->rc!=NULL){push(M1,g->rc);g=g->rc;break;}
          }
        } 
      }
    }
}

int main()
{
  int n;cin>>n;
  tree* t1=new tree(n);
  cin>>n;
  while(n!=-1){create(t1,n);cin>>n;}
  cin>>n;
  tree* t2=new tree(n);
  cin>>n;
  while(n!=-1){create(t2,n);cin>>n;} int sum;
  cin>>sum;
  stack M1,M2;
  psum(t1,t2,M1,M2,sum);
  return 0;
}