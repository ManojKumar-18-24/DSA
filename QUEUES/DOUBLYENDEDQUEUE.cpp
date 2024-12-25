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

void enqr(queue& Q,int x)
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

int deqf(queue &Q)
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


void enqf(queue& Q,int x)
{
    if(is_qfull(Q))
    {
        cout<<"full";
    }
    else
    {  
        if(Q.front==-1)
        {
            Q.front++;Q.rear++;
        }
        else if(Q.front==0)Q.front=Q.size-1;
        else Q.front--;
        Q.elements[Q.front]=x;
    }
}

int deqr(queue &Q)
{
    if(is_qempty(Q))
    {
        ;
    }
    else
    {
        int n=Q.elements[Q.rear];
        if((Q.rear)==0)
        {
            Q.rear=Q.size-1;
        }
        else
        {
            Q.rear--;
        }
        return n;
    }
}

void display()
{
    cout<<"1.DEQF \n 2.ENQF \n 3.DEQR \n 4.ENQR \nANY OTHER TO DISCONTINUE\n";
}

int main()
{
    queue Q;
    while(1)
    {
        display();int n;
        int p;cin>>p;
        if(p<=0 || p>4)break;
        switch(p)
        {
            case 1:deqf(Q);break;
            case 2:cin>>n;enqf(Q,n);break;
            case 3:deqr(Q);break;
            case 4:cin>>n;enqr(Q,n); break;
        }
        if(Q.front<Q.rear || (Q.front==0 && Q.rear==0))
        {
            for(int i=Q.front;i<=Q.rear;i++)cout<<Q.elements[i]<<" ";cout<<endl;
        }
        else
        {
            for(int i=Q.front;i<=Q.size-1;i++)cout<<Q.elements[i]<<" ";
            for(int i=0;i<=Q.rear;i++)cout<<Q.elements[i]<<" ";
            cout<<endl;
        }
    }
   return 0; 
}