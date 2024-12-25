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
 int i;queue Q;
 cin>>i;int j,c=0;
 while(i!=-1)
 {
    enq(Q,i);
    cin>>i;
 } 
 enq(Q,i);
 i=deq(Q);
 while(1)
 {
    j=deq(Q);
    //cout<<i<<" "<<j<<endl;
    if(j==-1)
    {   
       
        enq(Q,i); if(c==0)break;c=0;enq(Q,-1);i=deq(Q);
    }
    else if(i<j)
    {
        enq(Q,i);i=j;
    }
    else
    {
        enq(Q,j);if(i>j)c++;
    }
 }
 
 while(!is_qempty(Q))
 {
     cout<<deq(Q)<<" ";
 }
 return 0;
}