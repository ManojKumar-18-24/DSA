#include<bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

 TreeNode* constructMaximumBinaryTree(vector<int>& nums,int start=0,int end=0,int r=0)
    {
        int max=nums[start];
        int i=start+1,j=start;
        if(r==0)end=nums.size()-1;
        while(i<=end)
        {
            cout<<nums[i]<<" ";
            if(nums[i]>max)
            {
                max=nums[i];
                j=i;
            }
            i++;
        }
         TreeNode* T=new TreeNode(nums[j]);
      if(start<=j-1)  T->left=constructMaximumBinaryTree(nums,start,j-1,r+1);
      if(j+1<=end)  T->right=constructMaximumBinaryTree(nums,j+1,end,r+1);
        return T;
    }

int main()
{
  vector<int> v={3,2,1,6,0,5};
  cout<<constructMaximumBinaryTree(v);
return 0;
}