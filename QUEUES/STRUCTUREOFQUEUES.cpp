#include<iostream>
using namespace std;

struct three
{
    int x,y;
    char ch;
};

struct queue
{
 int size=50,front=-1,rear=-1;three elements[50];
};

bool is_qfull(queue Q)
{
  if((Q.rear+1)%Q.size==Q.front)
  return true;
  return false;
}

bool is_qempty(queue Q)
{  cout<<Q.front<<" "<<Q.rear<<endl;
  if(Q.front==-1 && Q.rear==-1)
  {return true;}
  return false;
}

void enq(queue& Q,three t)
{
    if(is_qfull(Q))
    {
      cout<<"it's full";
    }
    else
    {
     if(Q.front==-1)Q.front++;
     Q.rear=(Q.rear+1)%Q.size;
     Q.elements[Q.rear].x=t.x;
     Q.elements[Q.rear].y=t.y;
     Q.elements[Q.rear].ch=t.ch;
    }
}

three deq(queue &Q)
{
 if(is_qempty(Q))
 {
  cout<<"it's empty";
 }
 else
 { 
  three n=Q.elements[Q.front];
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

int operation(three t)
{  int n;
    switch(t.ch)
    {
        case 'A':n=t.x+t.y;break;
        case 'S':n=t.x-t.y;break;
        case 'M':n=t.x*t.y;break;
    }
    return n;
}

int main()
{
  three t;queue Q;
  cin>>t.x>>t.y>>t.ch;
  while(t.x!=-1 && t.y!=-1)
  {
    enq(Q,t);
    cout<<Q.front<<" "<<Q.rear<<endl;
     cin>>t.x>>t.y>>t.ch;
  }
  while(!(is_qempty(Q)))
  {
    t=deq(Q);
    cout<<operation(t)<<" ";
  }
  return 0;
}