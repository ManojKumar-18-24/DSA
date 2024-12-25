#include<iostream>
using namespace std;

struct queue
{
 int size=50,front=-1,rear=-1,elements[50];
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

void enq(queue& Q,int x)
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

int deq(queue &Q)
{
 if(is_qempty(Q))
 {
  cout<<"it's empty";
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
  int M,N;queue Q;
  cin>>M>>N;
  int i=0;
  while(i<N)
  {
      enq(Q,i);i++;
  }
  enq(Q,-1);
  N=0;
  while(1)
  { N++;
    i=deq(Q);
    if(i==-1){N--;if(is_qempty(Q))break;}
    if(N!=M)enq(Q,i);
    else{N=0;cout<<i<<" ";}
  }
  return 0;
}