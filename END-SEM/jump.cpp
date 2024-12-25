#include<bits/stdc++.h>
using namespace std;

    int jump(vector<int>& nums) 
    {
         int n=nums.size();
        if(n==1)return 0;
        vector<int> ans(n,0);
        ans[0]=0;
        for(int i=0;i<n;i++)
        {
            if(i==0 || ans[i]==1)
            {
            for(int j=i+1;j<n && j<=i+nums[i];j++)
            {
                cout<<j<<" ";
               if(ans[j]==0)ans[j]=ans[i]+1;
               else
               {
                   ans[j]=min(ans[j],ans[i]+1);cout<<"na";
               }
            }
            cout<<endl;
            }
        }
        cout<<ans[n-2];
        return ans[n-1];
    }

int main()
{
vector<int> ans={1,1,1,1};
cout<<jump(ans);
return 0;
}