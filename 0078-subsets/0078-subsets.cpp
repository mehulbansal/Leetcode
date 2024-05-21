class Solution {
public:
    
    void solve(vector<int>&nums, vector<int>layer, vector<vector<int>>&ans, int idx){
        if(idx == nums.size()) return;
        
        layer.push_back(nums[idx]);
        ans.push_back(layer);
        solve(nums, layer, ans, idx+1);
        layer.pop_back();
        solve(nums, layer, ans, idx+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        ans.push_back({});
        vector<int>layer;
        solve(nums, layer, ans, 0);
        return ans;
    }
};