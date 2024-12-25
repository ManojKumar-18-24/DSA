#include<iostream>
using namespace std;

struct queue
{
 int size,front=-1,rear=-1;unsigned char elements[50];
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

void enq(queue& Q,char x)
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

char deq(queue &Q)
{
 if(is_qempty(Q))
 {
  cout<<"it's empty";
 }
 else
 {
  char n=Q.elements[Q.front];
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

int operate(char a,char b,char c)
{ int n;
    switch(a)
    {
       case '+':n=(b-48)+(c-48);break;
       case '-':n=(b-48)-(c-48);break; 
       case '*':n=(b-48)*(c-48);break; 
       case '/':n=(b-48)/(c-48);break; 
    }
    n+=48;
    return n;
}
                                                        //  "-+*9+28*4863#"
void evaluate(queue &Q)
{
    char a=deq(Q), b=deq(Q), c=deq(Q);
    while(1)
    {   for(int i=Q.front;i<=Q.rear;i++)cout<<Q.elements[i]<<" ";cout<<endl;
        //while(1){ char ch=deq(Q);cout<<ch<<" ";enq(Q,ch); if(ch=='#')break;}cout<<endl;
        if(c=='#')
        {
            enq(Q,a);enq(Q,b);enq(Q,c);
            a=deq(Q), b=deq(Q), c=deq(Q);
        }
        if(a<48 && b>48 && c>48)
        {  
            cout<<operate(a,b,c)-48<<endl;
            enq(Q,operate(a,b,c));
            a=deq(Q);b=deq(Q);
            if(a=='#' && is_qempty(Q))
            {
                cout<<b-48;return;
            }
            else if(a=='#' && (!is_qempty(Q)))
            {
              a=b;b=deq(Q);c=deq(Q);
            }
            else if(b=='#')
            {
                enq(Q,a);enq(Q,b);
                a=deq(Q), b=deq(Q), c=deq(Q);
            }
        }
        else
        {
            enq(Q,a);a=b;b=c;
            c=deq(Q);
        }
    }
}

int main()
{
    queue Q;
  char P[]="-+*9+28*4863#";int i=0;
  while(P[i]!='#'){  enq(Q,P[i]); i++; }
  enq(Q,'#');
  evaluate(Q);
  return 0;
}