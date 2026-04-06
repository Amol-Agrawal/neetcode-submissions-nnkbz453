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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(!root) return "";
        string s  = "";

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr == nullptr) s.append("#,");
            else s.append(to_string(curr->val)+',');

            if(curr != nullptr) {
                q.push(curr->left);
                q.push(curr->right);
            }

        }

        return s;


    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if( data.size()== 0) return nullptr;

        stringstream s(data);

        string str;
        getline(s, str, ',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q ;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "#") {
                curr->left = nullptr;
            }else{
                TreeNode* lnode = new TreeNode(stoi(str));
                curr->left = lnode;
                q.push(lnode);
            }

            getline(s, str, ',');
            if(str == "#") {
                curr->right = nullptr;
            }else{
                TreeNode* rnode = new TreeNode(stoi(str));
                curr->right = rnode;
                q.push(rnode);
            }




        }

        return root;

    }
};
