#include<iostream>
using namespace std;

int Check(int G[5][5],int Visited[5])
{
  for(int i=0;i<5;i++)
  {
    if(Visited[i]==0)
    {
    int count=0;
    for(int j=0;j<5;j++)
    {
     if(i!=j && G[j][i])
     {
       count=1;
     }
    }
    if(count==0)
    {
        Visited[i]=1;
        return i;
    }
    }
  }
  return -1;
}

void CompleteCourse(int G[5][5],int Visited[5])
{
    int k=Check(G,Visited);
    if(k==-1)return;
    cout<<k<<" ";
     for(int i=0;i<5;i++)
     {
        G[k][i]=0;
     }
   CompleteCourse(G,Visited);
}

int main()
{
//   int NoofCourses;
//   cin>>NoofCourses;
  int G[5][5]={0};
  int i,j;
  cin>>i>>j;
  while(i!=-1 && j!=-1)
  {
    G[i][j]=1;
    cin>>i>>j;
  }
  int Visited[5]={0,0,0,0,0};
  CompleteCourse(G,Visited);
  return 0;
}