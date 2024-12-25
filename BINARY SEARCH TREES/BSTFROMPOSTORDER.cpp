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

int find(int a[100],int end,int start)
{
    int n=a[end];
    while(end>=start)
    {
      if(a[end]<n)break;end--;
    }
    return end;
}

void createfrompost(tree* &t,int a[100],int start,int end)
{
   t=new tree(a[end]);
   int i=find(a,end,start);
  if(i+1<end) createfrompost(t->rc,a,i+1,end-1);
  if(start<=i) createfrompost(t->lc,a,start,i);
}

void levelprint(queue Q)
{
     int product=2;int c=0,p=0;
     while(!is_qempty(Q))
     {
        tree* t=deq(Q);
       if(t==NULL){enq(Q,NULL);enq(Q,NULL);c+=2;}
       else
          {
             cout<<t->data<<" ";
             enq(Q,t->lc);enq(Q,t->rc);c+=2;p++;
          }
        if(c==product){product*=2;c=0;if(p==0)break;p=0;cout<<endl;}
      }
}

int main()
{
  int n,k=0;
  tree* t=NULL;int a[100];
  cin>>n;a[k]=n;
  k++;cin>>n;
  while(n!=-1) {a[k]=n;k++;cin>>n;} 
  createfrompost(t,a,0,k-1);
  queue Q;enq(Q,t);
  levelprint(Q);
  return 0;
}