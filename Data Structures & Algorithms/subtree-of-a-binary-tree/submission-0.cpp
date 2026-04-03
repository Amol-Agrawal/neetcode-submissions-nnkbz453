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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if( !subRoot){
            return true;
        }
        if(  !root) return false;

        // bool ans ;

        // ans = sametree(root ,subRoot);

        // if(ans == true) {return true;}
        // else{
        //     ans = isSubtree(root->left, subRoot);
        //     if(ans == true) {return true;}
        //     ans = isSubtree(root->right, subRoot);
        //     if(ans == true) {return true;}
        // }

        if(sametree(root, subRoot) ) {
            return true;
        }else{
           return (isSubtree(root->left, subRoot) ||
            isSubtree(root->right, subRoot));
        }
        
        
        
    }

    bool sametree(TreeNode* r1, TreeNode* r2){
        if( !r1 && !r2) return true;

        if(r1 && r2 &&  r1->val == r2->val ){
            return ( sametree(r1->left, r2->left) && sametree(r1->right, r2-> right) );
        }else return false;
    }


};
