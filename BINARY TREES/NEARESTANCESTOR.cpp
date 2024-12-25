#include<iostream>
using namespace std;

 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        int e=0;
        if(root==NULL)return NULL;
        else
        {
            TreeNode* g;TreeNode* f;
            if(root==p || root==q)
            {
               e++;
            }
             g=lowestCommonAncestor(root->left,p,q);
             f=lowestCommonAncestor(root->right,p,q);
            if(e>0 &&(g!=NULL ||f!=NULL))
            {
                return root;
            }
            else if(g!=NULL && f!=NULL)
            {
                return root;
            }
            else if(g!=NULL || f!=NULL || e>0) 
            {
               if(e>0) return root;
               if(g!=NULL)return g;
               return f;
            }
            else
            {
                return NULL;
            }
        } 
        return NULL;
    }
};

int main()
{
    return 0;
}