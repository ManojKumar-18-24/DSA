#include<iostream>
using namespace std;

int FindMin(int Visited[11],int Distance[11])
{
    int c=0,min=10000,j,i=0;
     for(i=0;i<11;i++)
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
    if(c==0)return -1;
    return j;
}

void FindShortestPath(int G[11][11],string S[11][11],int Distance[11],int store[11],int Visited[11],int Source)
{
  for(int i=0;i<11;i++){  if(Visited[i]==0 && G[Source][i]!=0 && G[Source][i]+Distance[Source]<Distance[i])  { Distance[i]=G[Source][i]+Distance[Source]; store[i]=Source;}}
  Visited[Source]=1;
  int k=FindMin(Visited,Distance);
  if(k+1)
  {
    FindShortestPath(G,S,Distance,store,Visited,k);
  }
}

void print(string S[11][11],int G[11][11],int store[11],int des,int sou)
{
    if(des==sou);
    else
    {
       print(S,G,store,store[des],sou);
       cout<<"From "<<store[des]<<" move "<<S[store[des]][des]<<" by ";
       cout<<G[store[des]][des]<<" to reach "<<des<<endl;
    }
}

int main()
{
  int G[11][11]={
               0,4,0,0,0,0,0,0,4,0,0,
               0,0,5,0,1,12,0,0,0,0,0,
               0,0,0,12,0,6,0,0,0,0,18,
               0,0,0,0,0,0,0,0,0,0,2,
               2,0,0,0,0,9,0,0,8,0,0,
               0,0,0,6,0,0,4,0,0,0,0,
               0,0,0,0,0,0,0,1,0,0,0,
               0,0,0,0,0,0,0,0,0,0,0,
               0,0,0,0,0,0,0,0,0,1,0,
               0,0,0,0,0,1,9,0,0,0,0,
               0,0,0,0,0,0,0,0,0,0,0,
               };
 string S[11][11]={""};
 S[0][4]="north-east";S[0][8]="south-east";S[1][4]="south";S[1][5]="south-east";S[1][2]="east";
 S[2][3]="east";S[2][10]="east";S[2][5]="south";S[3][10]="north-west";
 S[4][0]="west";S[4][5]="east";S[4][8]="south";S[5][3]="north-east";S[5][6]="east";
 S[6][7]="east";S[8][9]="east";S[9][6]="north-east";S[9][5]="north";
  int source,destination;cin>>source>>destination;
  int Distance[11];
  for(int i=0;i<11;i++) {   Distance[i]=9999; }
   Distance[source]=0;
  int Visited[11]={0,0,0,0,0,0,0,0,0,0,0};
  int store[11]={0};
  FindShortestPath(G,S,Distance,store,Visited,source);
  print(S,G,store,destination,source);
  cout<<"Minimum cost is "<<Distance[destination]<<endl;
return 0;
}