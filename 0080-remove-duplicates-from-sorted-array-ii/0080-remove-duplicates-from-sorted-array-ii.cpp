class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int rem = 0;
        
        for(int i = 0; i<nums.size(); i++){
            if(rem == 0 || rem == 1 || nums[rem-2]!=nums[i]){
                nums[rem] = nums[i];
                rem++;
                
            }
        }
        return rem;
    }
};