#include<iostream>
using namespace std;

struct queue
{
    int size=50,front=50,rear=-1,elements[50];
};

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
    cout<<"empty";
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
    cout<<"empty";
  }
  else
  {
    int n=Q.elements[Q.rear];
    Q.rear--;
    return n;
  }
}

int presedence(char lower,char upper)
{
 switch(lower)
 {
    case '+':if(upper=='*'||upper=='/')return false;else return true;
    case '-':if(upper=='*'||upper=='/')return false;else return true;
    case  '*':if(upper=='/')return false;else return true;
    case '/':return true;
 }
}

int main()
{
    queue Q;
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0')
        {
            enqr(Q,s[i]-'0');
        }
        else
        {
            if(Q.front==Q.size)
            {
                enqf(Q,s[i]);
            }
            else
            {
                char ch=deqf(Q);
                if(presedence(ch,s[i]))
                {
                    enqf(Q,ch);
                    while(Q.front!=Q.size)
                    {
                        ch=deqf(Q);
                        int n=deqr(Q),m=deqr(Q);
                         switch(ch)
                             {
                                case '+':enqr(Q,n+m);break;
                                case '-':enqr(Q,m-n);break;
                                case '*':enqr(Q,n*m);break;
                                case '/':enqr(Q,m/n);
                             }
                    }
                    enqf(Q,s[i]);
                }
                else
                {
                    enqf(Q,ch);
                    enqf(Q,s[i]);
                }
            }
        }
    }
                     while(Q.front!=Q.size)
                    {
                       char ch=deqf(Q);
                        int n=deqr(Q),m=deqr(Q);
                         switch(ch)
                             {
                                case '+':enqr(Q,n+m);break;
                                case '-':enqr(Q,m-n);break;
                                case '*':enqr(Q,n*m);break;
                                case '/':enqr(Q,m/n);
                             }
                    }
  cout<<deqr(Q);
    return 0;
}
