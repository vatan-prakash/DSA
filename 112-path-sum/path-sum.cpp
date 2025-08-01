/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   

    bool hasPathSum(TreeNode* root, int targetSum) {
        // int sum=0;
      
     if(!root) return false;
       if(root->left==nullptr && root->right==nullptr){
         if(targetSum==root->val) return true;
         else return false;
        }
         return hasPathSum(root->left, targetSum-root->val) + hasPathSum(root->right, targetSum-root->val);
    }
};