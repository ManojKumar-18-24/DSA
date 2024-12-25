#include<bits/stdc++.h>
using namespace std;

int came=0;

void ATDT(vector<vector<int>> G,vector<int> &visited,vector<pair<int,int>>& travel,vector<int> &tree,int source)
{

   int m=visited.size();
   for(int i=0;i<m;i++)
   {
    if(G[source][i]==1 && visited[i]==0)
    {
        G[source][i]=-1;
    }
   }
     visited[source]=1;
   travel[source].first=came;
   came++;
   for(int i=0;i<m;i++)
   {
    if(G[source][i]==-1 && visited[i]==0)
    {
        ATDT(G,visited,travel,tree,i);
        tree[i]=source;
    }
   }
   travel[source].second=came;
   came++;
}

void Nice(vector<vector<int>> G,vector<int> &visited,vector<int> tree,int source)
{
     int m=visited.size();
   for(int i=0;i<m;i++)
   {
    if(G[source][i]==1 && visited[i]==0)
    {
        G[source][i]=-1;
    }
   }
    for(int i=0;i<m;i++)
   {
    if(G[source][i]==-1)
    {
        Nice(G,visited,tree,i);
        tree[i]=source;
    }
   }  
}

int Say(vector<int> tree,int des,int sou)
{
  if(des==sou)return 1;
  else if(tree[des]==des)return 0;
  return Say(tree,tree[des],sou);
}

void TypeofEdge(vector<vector<int>> G,vector<int> &v,vector<int> tree,int source=0)
{
   for(int i=0;i<G.size();i++)
   {
     if(G[source][i]!=0)
     {
       if(tree[i]==source)
       {
         cout<<source<<" "<<i<<" "<<"T"<<endl;
       }
       else if(Say(tree,i,source))
       {
        cout<<source<<" "<<i<<" "<<"F"<<endl;
       }
       else if(Say(tree,source,i))
       {
        cout<<source<<" "<<i<<" "<<"B"<<endl;
       }
       else
       {
        cout<<source<<" "<<i<<" "<<"C"<<endl;
       }
       v[source]=1;
      if(v[i]==0) TypeofEdge(G,v,tree,i);
     }
   }
}

int main()
{
  vector<vector<int>> G;
  int n, j,k;
  cin>>n;
  vector<int> visited(n,0);
  for(int i=1;i<=n;i++)G.push_back(visited);
  cin>>j;
  for(int i=0;i<j;i++)
  {
    int l;
    cin>>l>>k;
    G[l][k]=1;
  }
  vector<pair<int,int>> travel(n,{0,0});
  vector<int> tree(n,0);
  for(int i=0;i<n;i++)tree[i]=i;
  ATDT(G,visited,travel,tree,0);
  for(int i=0;i<n;i++)
  {
    cout<<i<<" "<<travel[i].first<<" "<< travel[i].second<<endl;
    visited[i]=0;
  }
   TypeofEdge(G,visited,tree);
return 0;
}