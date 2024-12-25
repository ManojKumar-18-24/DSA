#include<iostream>
#include<vector>
using namespace std;

class TreeNode
{
    public:
    TreeNode* left;
    int data;
    TreeNode* right;
    TreeNode(int n)
    {
        left=NULL;
        data=n;
        right=NULL;
    }
};

       TreeNode* copy(TreeNode* org) 
       {
        if (org == nullptr) {
            return nullptr;
        }
        
        TreeNode* dup = new TreeNode(0);
        dup->left = copy(org->left);
        dup->right = copy(org->right);
        return dup;
        }

    void Make(TreeNode* root,vector<TreeNode*>&ans,int count)
    {
       if(count==0)
       {
            TreeNode* dup = copy(root);
            ans.push_back(dup);
       }
       else if(count>=2)
       {
           root->left=new TreeNode(0);
           root->right=new TreeNode(0);
           Make(root->left,ans,count-2);
           Make(root->right,ans,count-2);
       }
    }

    void allPossibleFBT(int n) {
           if (n % 2 == 0) {
           // return {}; 
        }
        vector<TreeNode*> ans;
        TreeNode* root=new TreeNode(0);
        Make(root,ans,n-1);
       // return ans;
    }

    int main()
    {
      int n; cin>>n;
     allPossibleFBT(n);
     return 0;
    }