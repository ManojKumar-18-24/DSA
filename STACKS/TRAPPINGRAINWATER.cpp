#include<iostream>
using namespace std;

struct stack
{
  int size;
  int elements[100];
  int top;
};

int min(int a,int b)
{
    if(a<b)return a;
    return b;
}
int peep(stack &M)
{
    return (M.top==-1)?0:M.elements[M.top];
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
 stack  M;
 M.top=-1;
 M.size=100;
 int n,p,c=0,sum=0;cin>>n;
 while(n!=-1)
 {
     if(n==0);
     else break;cin>>n;
 }
 p=n;
 while(n!=-1)
 { 
    if(c>1 && n<peep(M))
    {
        int k=min(p,peep(M));
        c=pop(M);
        while(M.top!=0)
        {
           if(peep(M)>p) pop(M) ;
           else
           {
               sum+=(p-pop(M));
           }
        }
        pop(M);
        push(M,c);
        p=peep(M);c=0;
    }
     push(M,n);
    if(n>=p)c++; 
    cin>>n;
 }
        pop(M);
        int k=min(p,peep(M));
        while(M.top!=-1)
        {
           if(peep(M)>p) pop(M) ;
           else
           {
               sum+=(p-pop(M));
           }
        }

 cout<<sum;
return 0;
}