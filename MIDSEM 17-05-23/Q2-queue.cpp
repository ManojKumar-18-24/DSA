#include<iostream>
using namespace std;

struct queue
{
 int size=50,front=-1,rear=-1,elements[50];
};

bool is_qfull(queue Q)
{
  if((Q.rear+1)%Q.size==Q.front%Q.size)
  return true;
  return false;
}

bool is_qempty(queue Q)
{ 
  if(Q.front==-1 && Q.rear==-1)
  return true;
  return false;
}

void enq(queue& Q,int x)
{
    if(is_qfull(Q))
    {
      cout<<"full";
    }
    else
    {
     if(Q.front==-1)Q.front=0;
     Q.rear=(Q.rear+1)%Q.size;
     Q.elements[Q.rear]=x;
    }
}

int deq(queue &Q)
{
 if(is_qempty(Q))
 {
  cout<<"empty";
 }
 else
 {
  int n=Q.elements[Q.front];
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

int main()
{
 queue Q1,Q2;
 int n,m,p=0;
 cin>>n;
 while(n!=-1)
 {
    enq(Q1,n); cin>>n;
 }
 enq(Q1,-1);
 cin>>n;
 while(n!=-1)
 {
    enq(Q2,n);cin>>n;
 }
 n=deq(Q1);m=deq(Q2);
 while(!is_qempty(Q1) && !is_qempty(Q2))
 {
    if(n==-1)
    {
        enq(Q1,m);p++;break;
    }
    if(m<n)
    {
        enq(Q1,m);m=deq(Q2);
    }
    else if(n<m)
    {
        enq(Q1,n);n=deq(Q1);
    }
    else
    {
        enq(Q1,n);m=deq(Q2);n=deq(Q1);
    }
 }
 if(p>0)
 {
    while(!is_qempty(Q2))
    {
        enq(Q1,deq(Q2));
    }
 }
 else
 {
    enq(Q1,n);
    n=deq(Q1);
    while(n!=-1)
    {
        enq(Q1,n);
        n=deq(Q1);
    }
 }
 while(!is_qempty(Q1))
 {
  cout<<deq(Q1)<<" ";
 }
return 0;
}