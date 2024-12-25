#include<iostream>
using namespace std;

struct stack
{
  int size=50;
  int elements[50];
  int top=-1;
};

int peep(stack &M)
{
    if(M.top!=-1)return M.elements[M.top];
    return -1;
}

int pop(stack &M)
{
    if(M.top!=-1)
    {
        return M.elements[M.top--];
    }
    return -1;
}

void push(stack &M,int x)
{
  if(M.top!=M.size-1);
  { 
    M.top++;
    M.elements[M.top]=x;
  }
}

void reverse(stack &S2,stack &S1)
{
  if(S2.top!=-1)
  {
    int n=pop(S2);
    reverse(S2,S1);
    push(S1,n);
  }
}

int main()
{
    int n;
    cin>>n;
    stack S1,S2,S3;
    while(n!=-1) {     push(S1,n);     cin>>n; }
    while(S1.top!=-1){    n=pop(S1);    if(n%2==0)push(S2,n);    else push(S3,n);}
    reverse(S2,S1);
    while(S1.top!=-1)push(S2,pop(S1));
    reverse(S3,S1);
    while(S1.top!=-1)push(S3,pop(S1));
    while(S3.top!=-1)push(S1,pop(S3));
    while(S2.top!=-1)push(S1,pop(S2)); 
    while(S1.top!=-1)cout<<pop(S1)<<" ";
    return 0;
}