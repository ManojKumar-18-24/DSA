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

struct queue
{
 int size=50,front=-1,rear=-1;tree *elements[50];
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

void levelprint(queue Q)
{
while(!is_qempty(Q))
{
    tree* t=deq(Q);
    if(t->lc!=NULL)
    {
        cout<<t->lc->data<<" ";
        enq(Q,t->lc);
    }
    if(t->rc!=NULL)
    {
      cout<<t->rc->data<<" ";
        enq(Q,t->rc); 
    }
}  
}

int main()
{
  int n;cin>>n;
  tree* t=new tree(n);
  cin>>n;
  while(n!=-1)
  {
     create(t,n);
     cin>>n;
  }
  queue Q;
  enq(Q,t);
  cout<<t->data<<" ";
 levelprint(Q);
  return 0;
}