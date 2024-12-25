#include<iostream>
using namespace std;

int FindMin(int Visited[5],int Distance[5])
{
    int c=0,min=10000,j,i=0;
     for(i=0;i<5;i++)
     {
        if(Visited[i]==0)
        {
            c=1;
            if(Distance[i]<min)
            {
              min=Distance[i];j=i;
            }
        }
     }
    if(c==0)return 0;
    return j;
}

void FindShortestPath(int G[5][5],int Distance[5],int Visited[5],int Source)
{
  for(int i=0;i<5;i++)
  {
    if(Visited[i]==0 && G[Source][i]!=0 && G[Source][i]+Distance[Source]<Distance[i])
    {
        Distance[i]=G[Source][i]+Distance[Source];
    }
  }
  Visited[Source]=1;
  int k=FindMin(Visited,Distance);
  if(k)
  {
    FindShortestPath(G,Distance,Visited,k);
  }
}

int main()
{
  int G[5][5]={
               0,2,8,5,0,
               0,0,1,0,0,
               0,0,0,0,3,
               0,0,0,0,4,
               0,0,0,0,0,
               };
  int source=0,destination;cin>>source>>destination;
  int Distance[5]={9999,9999,9999,9999,9999};
   Distance[source]=0;
  int Visited[5]={0,0,0,0,0};
  FindShortestPath(G,Distance,Visited,source);
  cout<<Distance[destination];
return 0;
}