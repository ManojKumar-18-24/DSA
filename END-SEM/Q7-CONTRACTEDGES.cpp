#include<bits/stdc++.h>
using namespace std;

pair<int,int> Findmin(int G[7][7])
{
  int min=999;
  pair<int,int> p={-1,-1};
  for(int i=0;i<7;i++)
  {
    for(int j=0;j<7;j++)
    {
        if(G[i][j]!=0 && G[i][j]<min)
        {
            min=G[i][j];
            p.first=i;p.second=j;
        }
    }
  }
  return p;
}

int co=0;

void change(int G[7][7])
{
    pair<int,int> p=Findmin(G);
    if(p.first==-1 && p.second==-1)return;
    cout<<p.first<<" "<<p.second<<" "<<G[p.first][p.second]<<endl;
    co+=G[p.first][p.second];
    G[p.first][p.second]=0;
    G[p.second][p.first]=0;
    for(int i=0;i<7;i++)
    {
        if(G[p.second][i]!=0)
        {
            if(G[p.first][i]==0)
            {
                G[p.first][i]=G[p.second][i];
                G[i][p.first]=G[p.second][i];
            }
            else if(G[p.first][i]>G[p.second][i])
            {
                 G[p.first][i]=G[p.second][i];
                 G[i][p.first]=G[p.second][i];
            }
            G[p.second][i]=0;
            G[i][p.second]=0;
        }
    }
    change(G);
}

int main()
{
 int G[7][7]={0};
 G[0][6]=8;G[0][1]=5;G[6][1]=10;G[6][4]=18;
 G[6][5]=2;G[5][1]=3;G[4][5]=12;G[5][2]=30;
 G[4][3]=4;G[3][2]=26;G[1][2]=16;G[5][3]=14;
 G[6][0]=8;G[1][0]=5;G[1][6]=10;G[4][6]=18;
 G[5][6]=2;G[1][5]=3;G[5][4]=12;G[2][5]=30;
 G[3][4]=4;G[2][3]=26;G[2][1]=16;G[3][5]=14;
 change(G);
 cout<<co;
return 0;
}