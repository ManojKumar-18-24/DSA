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
    queue Q;string s;
    cin>>s;
    for(int i=s.length()-1;i>=0;i--)
    {
       if(s[i]>48)enq(Q,s[i]-48);
       else
       { enq(Q,-1);
         int p,q,r;
         p=deq(Q);q=deq(Q);r=deq(Q);
         while(r!=-1)
         {  enq(Q,p);
            p=q;q=r;r=deq(Q);
         }
         switch(s[i])
         {
            case '+':enq(Q,p+q);break;
            case '-':enq(Q,q-p);break;
            case '*':enq(Q,p*q);break;
            case '/':enq(Q,q/p);break;
         }
       }
    }
    cout<<deq(Q);
    return 0;
}