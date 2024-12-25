#include<bits/stdc++.h>
using namespace std;

void find(int n,vector<int>&visit,int &maxi,int pro,int sum=0,int i=0)
{
    //cout<<sum+pro<<endl;
   if(i==n)
   {
     if(sum-pro>maxi)maxi=sum-pro;
   }
   else
   {
       for(int j=0;j<n;j++)
       {
        if(visit[j]==0)
        {
             int q=(j+1)*(i+1);
             visit[j]=1;
            if(q>pro)find(n,visit,maxi,q,sum+q,i+1);
            else find(n,visit,maxi,pro,sum+q,i+1);
            visit[j]=0;
        }
       }
   }
}

int main()
{
int t;
cin>>t;
for(int i=0;i<t;i++)
{
    int n;
    cin>>n;
    int maxi=INT_MIN;
    vector<int> visit(n,0);
    find(n,visit,maxi,INT_MIN);
    cout<<maxi<<endl;
}
return 0;
}