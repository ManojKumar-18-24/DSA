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

void set(queue Q,tree* &hptr,int x)
{
    enq(Q,hptr);
    if(hptr==NULL){hptr=new tree(x);return;}
    tree* k;
    while(1)
    {
        k=deq(Q);
        if(k->lc==NULL)
        {
            k->lc=new tree(x);return;
        }
        else enq(Q,k->lc);
        if(k->rc==NULL)
        {
            k->rc=new tree(x);return;
        }
        else enq(Q,k->rc);
    }
}

void traversal(tree* bsptr,tree* &hptr,queue Q)
{
    if(bsptr!=NULL)
    {
        traversal(bsptr->lc,hptr,Q);
        set(Q,hptr,bsptr->data);
        traversal(bsptr->rc,hptr,Q);
    }
}

void print(tree* t)
{
 if(t!=NULL)
 {
    cout<<t->data<<" ";
    print(t->lc);
    print(t->rc);
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
  };
  queue Q;
  tree* hptr=NULL;
  traversal(t,hptr,Q);
  print(hptr);
  return 0;
}