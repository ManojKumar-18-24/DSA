#include<iostream>
using namespace std;

void BFT(int G[9][9],int Visited[9],int node)
{
   if(Visited[node]==0)cout<<node<<" ";
   for(int i=0;i<9;i++)
   {
    if(G[node][i]==1 && Visited[i]==0)
    {  
        cout<<i<<" ";
        Visited[i]=1;
        G[node][i]=-1;
    }
   }
   Visited[node]=1;
   for(int i=0;i<6;i++)
   {
    if(G[node][i]==-1)BFT(G,Visited,i);
   }
}

int main()
{
int G[9][9]=
     {
        0,1,0,1,1,0,0,0,0,
        0,0,1,0,0,0,0,0,0,
        0,0,0,0,0,1,0,0,0,
        0,0,0,0,1,0,1,0,0,
        0,0,0,0,0,1,0,1,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,1,0,1,0,0,
        0,0,0,0,0,1,0,0,1,
        0,0,0,0,0,0,0,0,0,
     };
  int Visited[9]={0,0,0,0,0,0,0,0,0};
  BFT(G,Visited,0);
return 0;
}