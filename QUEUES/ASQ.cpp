#include<iostream>
using namespace std;

struct queue
{
 int size=50,front=-1,rear=-1,elements[50];
};

struct stack
{
  int size=100;
  int elements[100];
  int top=-1;
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

int peep(stack &M)
{
   return (M.top==-1)? -1:M.elements[M.top];
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

int main()
{
    stack M;queue Q;
    int a[100],b[100],c[100];
    int i=0;cin>>a[i];
    while(a[i]!=-1)
    {
       push(M,a[i]);
       i++;
       cin>>a[i];
    }
    i=0;cin>>b[i];
    while(b[i]!=-1)
    {
       enq(Q,b[i]);
       i++;
       cin>>b[i];        
    }
    while(!is_qempty(Q))
    {
        push(M,deq(Q));
    }
    while(M.top!=-1)
    {
        enq(Q,pop(M));
    }
    while(!is_qempty(Q))
    {
        push(M,deq(Q));
    } i=0;
    while(M.top!=-1)
    {
       c[i]=pop(M);
       i++;
    }
    int j=0;
    while(j<i)
    {
        cout<<c[j]<<" ";j++;
    }
    return 0;
}
