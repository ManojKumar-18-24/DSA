#include<iostream>
using namespace std;

struct three
{
   int v1;
   int v2;
   int cost;
};

three FindMin(int G[8][8])
{
  three req;
  req.cost=999;
  for(int i=0;i<8;i++)
  {
    for(int j=0;j<8;j++)
    {
      if(G[i][j]>0 && G[i][j]<req.cost)
      {
         req.cost=G[i][j];
         req.v1=i;
         req.v2=j;
      }
    }
  }
  return req;
}

int Find(int A[8],int i)
{
  if(A[i]==i)return i;
  return Find(A,A[i]);
}

int  KRUSKALSMAGIC(int G[8][8],int A[8])
{
  three req=FindMin(G);
  if(req.cost==999)return 0;
  G[req.v1][req.v2]=-1;
  cout<<req.v1<<" "<<req.v2<<endl;
  if(Find(A,req.v1)!=Find(A,req.v2))
  {
    cout<<req.v1<<" "<<req.v2<<" "<<1<<endl;
    A[req.v1]=Find(A,req.v2);
    return(req.cost+KRUSKALSMAGIC(G,A));
  }
  cout<<req.v1<<" "<<req.v2<<" "<<0<<endl;
  return KRUSKALSMAGIC(G,A);
}

int main()
{
  int G[8][8]={0};
  G[1][2]=2;G[1][3]=4;G[1][4]=1;G[2][4]=3;
  G[2][5]=10;G[5][4]=7;G[3][4]=2;G[3][6]=5;
  G[4][6]=8;G[4][7]=4;G[6][7]=1;G[5][7]=6;
  int A[8];
  for(int i=0;i<8;i++)A[i]=i;
  cout<<KRUSKALSMAGIC(G,A);
  return 0;
}