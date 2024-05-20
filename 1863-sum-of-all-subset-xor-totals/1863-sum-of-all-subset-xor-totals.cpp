class Solution {
public:
    void allsubsets(vector<vector<int>>&subsets, vector<int>&layer, vector<int>& nums, int id){
        subsets.push_back(layer);
        for(int i = id; i<nums.size(); i++){
            layer.push_back(nums[i]);
            allsubsets(subsets, layer, nums, i+1);
            layer.pop_back();
        }
    }
    
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>>subsets ;
        vector<int>layer;
        allsubsets(subsets,layer,nums,0);
        int ans = 0;
        for(int i = 0; i<subsets.size(); i++){
            int total = 0;
            for(int j = 0; j<subsets[i].size(); j++){
                total = total^subsets[i][j];
            }
            ans+=total;
        }
        return ans;
    }
    
};