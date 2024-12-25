#include<iostream>
using namespace std;

void DFS(int G[6][6],int Visited[6],int node)
{
   cout<<node<<" ";
   for(int i=0;i<6;i++)
   {
    if(G[node][i]==1 && Visited[i]==0)
    {  
        Visited[i]=1;
        G[node][i]=-1;
    }
   }
   Visited[node]=1;
   for(int i=0;i<6;i++)
   {
    if(G[node][i]==-1)DFS(G,Visited,i);
   }
}

int main()
{
 int G[6][6]=
 {
    0,1,1,0,0,0,
    0,0,1,1,0,0,
    0,0,0,1,0,0,
    0,0,0,0,1,0,
    1,1,0,0,0,1,
    0,0,0,0,0,0,
 };
 int Visited[6]={0,0,0,0,0,0};
 int node;
// cin>>node;
 node=0;
 DFS(G,Visited,node);
 return 0;
}