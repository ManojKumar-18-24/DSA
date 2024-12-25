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
    
    int Findlevel(TreeNode* root,int level=0)
    {
      if(root)
      {
          int m=Findlevel(root->left,level+1);
          int n=Findlevel(root->right,level+1);
          return max(m,n);
      }
      return level-1;
    }

    void FindSum(TreeNode* root,vector<int> &v,int level=0)
    {
       if(root)
       {
           v[level]+=root->val;
           FindSum(root->left,v,level+1);
           FindSum(root->right,v,level+1);
       }
       return;
    }

    void Get(TreeNode* root,TreeNode* parent,vector<int> v,vector<int> &v2,int level=0)
    {
        if(root)
        {
          if(root!=parent)
          {
            if(parent->left==root)
            {
                if(parent->right)
                {
                    v2.push_back(v[level]-(parent->right->val)-(root->val));
                }
                else v2.push_back(v[level]-(root->val));
            }
            else
            {
                if(parent->left)
                {
                    v2.push_back(v[level]-(parent->left->val)-(root->val));
                }
                else v2.push_back(v[level]-root->val);               
            }
          }
          Get(root->left,root,v,v2,level+1);
          Get(root->right,root,v,v2,level+1);
        }
        return;
    }

    TreeNode* replaceValueInTree(TreeNode* root) 
    {
     int n=Findlevel(root);
     vector<int> v(n+1,0);
     FindSum(root,v);
     vector<int> v2(10000,0);
     Get(root,root,v,v2);
     for(int i=0;i<10;i++)cout<<v2[i]<<" ";
     return root;
    }