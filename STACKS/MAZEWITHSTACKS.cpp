#include<iostream>
using namespace std;

struct stack
{
  int size;
  int elements[100];
  int top;
};

void peep(stack &M)
{
    (M.top==-1)?cout<<"empty":cout<<M.elements[M.top]<<" ";
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

int say(int a[8][8],int sx,int sy)
{ int p=0;
  if(a[sx+1][sy]==1)p++;
  if(a[sx][sy+1]==1)p++;
  if(a[sx-1][sy]==1)p++;
  if(a[sx][sy-1]==1)p++; 
  if(p==3) return true;
  return false;
}


int main()
{
 stack  M;
 M.top=-1;
 M.size=100;
 int a[8][8]={0},sx,sy,dx,dy;
 for(int i=0;i<8;i++)
 {
    for(int j=0;j<8;j++)
    {
       if(i==0 ||j==0 ||i==7|| j==7)a[i][j]=1;
       if(i==2 && (j>3)) a[i][j]=1;
       if(j==5&& (i>3)) a[i][j]=1;
       if(j==2)
       {
        if(i>1 && i<6)a[i][j]=1;
       }
    }
 } a[3][1]=1;a[4][3]=1;a[4][4]=1;a[5][3]=1;
 cin>>sx>>sy>>dx>>dy;int t=0;
 push(M,sx);push(M,sy);
 while(1)
 {   
    a[sx][sy]=2;
   if(sx==dx && sy==dy)
    {
      cout<<1<<endl;break;
    }
   if( t>0 && say(a,sx,sy))
   {
     a[sx][sy]=1;
     int r=pop(M);r=pop(M);
     sy=pop(M);sx=pop(M); 
   }
   if(  a[sx+1][sy]!=1)
   { sx++;
     push(M,sx);push(M,sy);
   }
   else  if(a[sx][sy+1]!=1)
   { sy++;
    push(M,sx);push(M,sy); 
   }
   else if(a[sx-1][sy]!=1)
   { sx--;
    push(M,sx);push(M,sy);
   }
   else if (a[sx][sy-1]!=1)
   {
    sy--;
    push(M,sx);push(M,sy);
   }
   else
   {
    cout<<"0"<<endl;
    break;
   } t++;
 }
return 0;
}