class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = INT_MIN;
        for(int i = 0; i<nums.size()-1; i++){
            bool flag = false;
            int z = nums[i];
            for(int j = i+1; j<nums.size(); j++){
                if(nums[j]==-z){
                    flag = true;
                    break;
                }
            }
            if(flag == true){
                ans = max(ans, abs(z));
            }
        }
        if(ans == INT_MIN) return -1;
        return ans;
    }
};