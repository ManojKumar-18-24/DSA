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
 
 return NULL;
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

void levelprint(queue Q,stack &S)
{
while(!is_qempty(Q))
{
    tree* t=deq(Q);
    if(t->lc!=NULL)
    {
        push(S,t->lc);
        enq(Q,t->lc);
    }
    if(t->rc!=NULL)
    {
      push(S,t->rc);
        enq(Q,t->rc); 
    }
}  
}

void levelprint3(queue Q,stack &S)
{
while(!is_qempty(Q))
{
    tree* t=deq(Q);
    if(t->rc!=NULL)
    {
        push(S,t->rc);
        enq(Q,t->rc);
    }
    if(t->lc!=NULL)
    {
      push(S,t->lc);
        enq(Q,t->lc); 
    }
} 
}

void sqlevelorderclock(queue Q,stack M)
{
    int product=2;int c=0,s=0,p=0;
 while(!is_qempty(Q))
 {
    tree* t=deq(Q);
    if(s==0)
    {
        if(t==NULL)
        {
            push(M,NULL);push(M,NULL);c+=2;
        }
        else
        {
            cout<<t->data<<" ";p++;
            push(M,t->rc);push(M,t->lc);c+=2;
        }
    }
    else
    {
        if(t==NULL)
        {
            push(M,NULL);push(M,NULL);c+=2;
        }
        else
        {
            cout<<t->data<<" ";p++;
            push(M,t->lc);push(M,t->rc);c+=2;
        }
    }
    if(c==product)
    {
        product*=2;c=0;if(s==0)s=1;else s=0;if(p==0)break;p=0;
        while(M.top!=-1)
        {
            enq(Q,pop(M));
        }
    }
 }
}

void squirellevelorderanti(queue Q,stack M)
{
    int product=2;int c=0,s=0,p=0;
 while(!is_qempty(Q))
 {
    tree* t=deq(Q);
    if(s==1)
    {
        if(t==NULL)
        {
            push(M,NULL);push(M,NULL);c+=2;
        }
        else
        {
            cout<<t->data<<" ";p++;
            push(M,t->rc);push(M,t->lc);c+=2;
        }
    }
    else
    {
        if(t==NULL)
        {
            push(M,NULL);push(M,NULL);c+=2;
        }
        else
        {
            cout<<t->data<<" ";p++;
            push(M,t->lc);push(M,t->rc);c+=2;
        }
    }
    if(c==product)
    {
        product*=2;c=0;if(s==0)s=1;else s=0;if(p==0)break;p=0;
        while(M.top!=-1)
        {
            enq(Q,pop(M));
        }
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
  queue Q;stack S;
  enq(Q,t);
  push(S,t);
  cout<<t->data<<" ";
  levelprint(Q);cout<<endl;
  levelprint(Q,S);
  while(S.top!=-1) {  cout<<pop(S)->data<<" "; }cout<<endl;
   levelprint3(Q,S);
   while(S.top!=-1) {  cout<<pop(S)->data<<" ";  }cout<<t->data<<endl;
   squirellevelorderanti(Q,S);cout<<endl;
   sqlevelorderclock(Q,S);cout<<endl;
   squirellevelorderanti(Q,S);cout<<endl;
   sqlevelorderclock(Q,S);cout<<endl;
  return 0;
}