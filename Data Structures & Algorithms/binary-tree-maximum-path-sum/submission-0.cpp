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

        
    int maxPathSum(TreeNode* root) {
        
        int maxsum = root->val;
        helper(root, maxsum);
        return maxsum;


    }

    int helper(TreeNode* root, int& maxsum) {
        if(root == nullptr) return 0;
    
        int left = max(helper(root->left,maxsum ), 0);
        int right = max(helper(root->right, maxsum),0);

        maxsum = max( maxsum, root->val + left+right);

        return root->val + max( left, right);
    }


};
