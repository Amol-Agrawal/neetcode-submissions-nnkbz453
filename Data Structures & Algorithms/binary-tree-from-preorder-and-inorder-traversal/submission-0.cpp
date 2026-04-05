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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if(preorder.size() != inorder.size()) return nullptr;
        unordered_map< int, int> mp ;

        for(int i = 0; i < inorder.size() ; i++ ){           
            mp[inorder[i]]= i;
        }

        int ps = 0; int pe = preorder.size()-1;
        int is = 0 ; int ie = inorder.size()-1;

        return prebuild( preorder, ps, pe, inorder, is, ie , mp);


    }


    TreeNode* prebuild(vector<int>&preorder, int  ps ,int  pe, vector<int>& inorder, int is, int ie,unordered_map< int, int>& mp ){

        TreeNode* root = new TreeNode( preorder[ps]);
        if(ps > pe || is > ie ) return nullptr;

        int numroot = mp[root->val];
        int leftsize = numroot - is;
        
        root->left = prebuild(preorder, ps+1, ps+leftsize,
                              inorder, is, numroot-1, mp);

        root->right = prebuild(preorder, ps+leftsize+1, pe,
                               inorder, numroot+1, ie, mp);

        return root ;


    }
};
