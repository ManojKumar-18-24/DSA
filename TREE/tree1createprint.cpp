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

void bftprint(tree* t)
{
   queue Q;
  enq(Q,t);enq(Q,NULL);
  while(!is_qempty(Q))
  {
    tree* g=deq(Q);
    if(g!=NULL){cout<<g->data<<" ";g=g->fc;}
    else
    {
      cout<<"/"<<endl;
      if(is_qempty(Q))return;
      enq(Q,NULL);
    }
    while(g)
    {
      enq(Q,g);g=g->ns;
    }
  }
}

void dftprint(tree* t)
{
  if(t!=NULL)
  {
    cout<<t->data;
    dftprint(t->fc);
    dftprint(t->ns);
  }
}

int main()
{
  tree* t;
  create(t);
  bftprint(t);
  dftprint(t);
  return 0;
}