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

void createbtree(tree* &t,int a[],int n)
{
    static int i=0;
    if(i==n)return;
    else if(a[i]!=0)
    {
        t=new tree(a[i]);i++;
        createbtree(t->lc,a,n);i++;
        createbtree(t->rc,a,n);
    }
}


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
 return NULL;
}

void createloop(tree* &t,int i)
{
    static int p=0;static tree* t1;static tree* t2;
    if(t==NULL);
    else if(t->rc==NULL && t->lc==NULL)
    {
        p++;if(p<=i)t1=t;else t2=t;
        if(p==2*i)
        {
            tree* g=new tree(t1->data+t2->data);
            t1->rc=g;t2->lc=g;p=0;
        }
    }
    else
    {
        createloop(t->lc,i);
        createloop(t->rc,i);
    }
}

void print(tree* t)
{
    if(t==NULL);
    else
    {
        cout<<t->data<<" ";
        print(t->lc);
        print(t->rc);
    }
}

void levelprinting(queue Q)
{
        int product=2;int c=0,p=0,k=0;
 while(!is_qempty(Q))
 { 
    tree* t=deq(Q);
    if(t==NULL){enq(Q,NULL);enq(Q,NULL);c+=2;}
    else
    {
      if(t->data!=k){cout<<t->data<<" ";k=t->data;}
      enq(Q,t->lc);enq(Q,t->rc);c+=2;p++;
    }
    if(c==product){product*=2;c=0;if(p==0)break;p=0;cout<<"\\"<<endl;}
 }
}

int main()
{
    int a[]={1,2,4,8,0,0,9,0,0,5,10,0,0,11,0,0,3,6,12,0,0,13,0,0,7,14,0,0,15,0,0};
   tree* t; createbtree(t,a,31);
    createloop(t,1);createloop(t,2);createloop(t,4) ;
    queue Q;
    enq(Q,t);levelprinting(Q);
    return 0;
}