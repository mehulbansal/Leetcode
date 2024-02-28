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
    
    int height(TreeNode* root){
        if(root == NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return max(lh,rh)+1;
    }
    
    void lot(TreeNode* root, int h, vector<int>& ans){
        if(root==NULL) return;
        if(h==1){ ans.push_back(root->val); return;}
        else if(h>1){
            lot(root->left, h-1, ans);
            lot(root->right, h-1, ans);
        }
        
    }
    
    int findBottomLeftValue(TreeNode* root) {
        int h = height(root);
        vector<int> ans;
        lot(root, h, ans);
        return ans[0];
    }
};