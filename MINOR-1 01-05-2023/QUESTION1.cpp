#include<iostream>
using namespace std;

struct queue
{
    int size=100;
    int elements[100];
    int front=100;
    int rear=-1;
};


struct stack
{
  int size=100;
  int elements[100];
  int top=-1;
};

int peep(stack &M)
{
    return (M.top==-1)?-1:M.elements[M.top];
}

int pop(stack &M)
{
    return ( M.top==-1)?-1: M.elements[M.top--];
}

void push(stack &M,int x)
{
  if(M.top==M.size-1);
  else
  { 
    M.top++;
    M.elements[M.top]=x;
  }
}

int isq_full(queue Q)
{
   if(Q.rear+1==Q.front)return true;
   return false;
}

void enqf(queue &Q,int x)
{
  if(isq_full(Q))
  {
    cout<<"its full ";
  }
  else
  {
     if(Q.front==0)Q.front=Q.size;
     Q.front--;
     Q.elements[Q.front]=x;
  }
}

void enqr(queue& Q,int x)
{
   if(isq_full(Q))
  {
    cout<<"its full";
  }
  else
  {
     if(Q.rear==Q.size-1)Q.rear=-1;
     Q.rear++;
     Q.elements[Q.rear]=x;
  }   
}

int deqf(queue& Q)
{
  if(Q.front==Q.size)
  {
    return -1;
  }
  else
  {
    int n=Q.elements[Q.front];
    Q.front++;
    return n;
  }
}

int deqr(queue &Q)
{
   if(Q.rear==-1)
  {
    return -1;
  }
  else
  {
    int n=Q.elements[Q.rear];
    Q.rear--;
    return n;
  }
}

int main()
{
  queue Q;int n,m,p;
  stack M;
  cin>>n;push(M,n);
  cin>>n;
 while(n!=-1)
 {
  push(M,n);cin>>n;
 }
 n=pop(M);
 enqr(Q,n);
 while(M.top!=-1)
 {
  p=peep(M);
  while(1)
  {
    m=deqr(Q);
    if(m<p)
    {
      if(m!=-1)enqr(Q,m);enqr(Q,pop(M));
      break;
    }
    else enqf(Q,m);
  }
  while(Q.front!=Q.size)
  {
    enqr(Q,deqf(Q));
  }
 }
 while(Q.rear!=-1)
 {
  push(M,deqr(Q));
 }
 while(M.top!=-1)
 {
  cout<<pop(M)<<" ";
 }
 return 0;
}