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
    void solve(TreeNode*& root, int val, int depth){
        if(root == NULL) return;
        if(depth == 0){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            root = node;
            return;
        }
        if(depth == 1){
            TreeNode* nodel = new TreeNode(val);
            nodel->left = root->left;
            root->left = nodel;
            TreeNode* noder = new TreeNode(val);
            noder->right = root->right;
            root->right = noder;
            return;
        } 
        solve(root->left, val, depth-1);
        solve(root->right, val, depth-1);
        return;

    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        solve(root, val, depth-1);
        return root;
    }
};