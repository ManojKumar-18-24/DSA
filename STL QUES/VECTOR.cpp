#include<bits/stdc++.h>
using namespace std;

int main()
{
 vector<vector<int>> nums;
 nums={{1,2},{1,1},{1,2},{1,-9}};
 sort(nums.begin(),nums.end());
 for(int i=0;i<nums.size();i++)
 {
    for(int j=0;j<2;j++)
    {
        cout<<nums[i][j]<<" ";
    } cout<<endl;
 }
return 0;
}