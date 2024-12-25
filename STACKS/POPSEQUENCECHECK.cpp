#include<iostream>
using namespace std;

struct stack
{
  int size;
  int elements[100];
  int top;
};

int peep(stack &M)
{
   return (M.top==-1) ?-1:M.elements[M.top];
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
 int a[6],b[6];
 for(int i=0;i<6;i++)cin>>a[i];
 for(int i=0;i<6;i++)cin>>b[i];
 int i=0,k=0;

 while(1)
 {
   if(i>=6)break;
   if(M.top!=-1 && b[k]==peep(M))
   {
     cout<<"X";
     int h=pop(M);k++;
   }
   else if(a[i]==b[k]){cout<<"SX";i++;k++;}
   else if(a[i]!=b[k])
   { cout<<"S";
    push(M,a[i]);i++;
   }
   else
   {
    if(a[i]==b[k])
    { cout<<"SX";
      i++;k++;
    }
   }
 }

 while(1)
 { if(k==6)break;
  if(peep(M)==b[k]){cout<<"X";int h=pop(M);k++;}
  else break;
 }
return 0;
}