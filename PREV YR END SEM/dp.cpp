#include <bits/stdc++.h>
using namespace std;
 
bool subsetSumToK(int n, int k, vector<int> &arr) {
   if(arr[0]==k)return true;
   vector<vector<int>> dp(n,vector<int>(k+1,-1));
   dp[0][1]=0;
   if(arr[0]<k)dp[0][arr[0]]=arr[0];
   for(int i=1;i<n;i++)
   {
       for(int j=1;j<=k;j++)
       {
          if(dp[i-1][j]!=-1)
          {
              if(dp[i-1][j]+arr[i]==k)return true;
              else if(dp[i-1][j]+arr[i]<k)
              {
                  dp[i][dp[i-1][j]+arr[i]]=dp[i-1][j]+arr[i];
              }
              dp[i][j]=dp[i-1][j];
          }
       }
   }
   return false;
}

int main() 
{
    int n = 5;
    int k = 4;
    vector<int> arr = {2, 5, 1, 6, 7};
    cout << (subsetSumToK(n, k, arr) ? "Subset with sum found" : "No subset with sum found") << endl;
    return 0;
}
