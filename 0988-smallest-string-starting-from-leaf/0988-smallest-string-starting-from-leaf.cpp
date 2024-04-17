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
    
    void solve(TreeNode* root, string& path, string& ans){
        if(root == NULL) return;
        
        path+=('a'+root->val);
        
        if(root->left == NULL and root->right==NULL){
            reverse(path.begin(), path.end());
            if(ans.empty() or path<ans){
                ans = path;
            }
            reverse(path.begin(), path.end());
        }
        
        
        solve(root->left, path, ans);
        
        solve(root->right, path, ans);
        path.pop_back();
        
        
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string ans = ""; 
        string path = "";
        solve(root, path, ans);
        return ans;
    }
};