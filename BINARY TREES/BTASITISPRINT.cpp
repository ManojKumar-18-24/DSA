#include<iostream>
using namespace std;

class tree
{
    public:
    tree* lc;
    int data;
    int x;
    int y;
    tree* rc;
    tree(int n)
    {
        lc=NULL;
        data=n;
        rc=NULL;
        x=0;
        y=0;
    }
};

int j=0;

struct queue
{
 int size=1000,front=-1,rear=-1;tree *elements[1000];
};

bool is_qfull(queue Q)
{
  if((Q.rear+1)%Q.size==Q.front)
  return true;
  return false;
}

bool is_qempty(queue Q)
{ 
  if(Q.front==-1 && Q.rear==-1)
  return true;
  return false;
}

void enq(queue& Q,tree* x)
{
    if(is_qfull(Q))
    {
      cout<<"it's full";
    }
    else
    {
     if(Q.front==-1)Q.front++;
     Q.rear=(Q.rear+1)%Q.size;
     Q.elements[Q.rear]=x;
    }
}

tree* deq(queue &Q)
{
 if(is_qempty(Q))
 {
  cout<<"it's empty";
 }
 else
 {
  tree* n=Q.elements[Q.front];
  if(Q.front==Q.rear)
  {
    Q.front=-1;Q.rear=-1;
  }
  else
  {
    Q.front=(Q.front+1)%Q.size;
  }
  return n;
 }
}

void createbtree(tree* &t)
{
   int n;cin>>n;
   if(n!=0)
   {
    t=new tree(n);
    createbtree(t->lc);
    createbtree(t->rc);
   }
}

void getyandx(tree* t,int i=0)
{ 
    if(t==NULL);
    else
    {
        getyandx(t->lc,i+1);
        t->x=j;t->y=i;j++;
        getyandx(t->rc,i+1);
    }
}

void asitisprint(queue Q)
{
      int product=2;int c=0,p=0,i=0;
 while(!is_qempty(Q))
 {
    tree* t=deq(Q);
    if(t==NULL){enq(Q,NULL);enq(Q,NULL);c+=2;}
    else
    {
      while(i<t->x){cout<<"*";i++;}
      cout<<t->data;i++;
      enq(Q,t->lc);enq(Q,t->rc);c+=2;p++;
    }
    if(c==product)
    {
      product*=2;c=0;if(i!=j)i--;
      if(p==0)break;p=0;while(i<j-1){cout<<"*";i++;}i=0;  cout<<endl;
    }
 }
}

int main()
{
  tree* t=NULL;
  createbtree(t);
  getyandx(t);queue Q;enq(Q,t);
  asitisprint(Q);
  return 0;
}