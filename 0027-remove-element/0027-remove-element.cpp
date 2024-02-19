class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = nums.size()-1;
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]=='_') break;
            if(nums[i]==val){
                ans++;
                while(i<=j and j>=0 and j<=nums.size()-1 and nums[j]==val){
                    nums[j] = '_';
                    j--;
                }
                if(j<=0) return j+1;
                if(i>j)break;
                if(nums[i]!='_' and nums[j]!='_'){
                    nums[i]=nums[j];
                    nums[j]='_';
                    j--;
                }
            }
            // else ans++;
        }
        // for(auto x: nums){
        //     cout<<x<<" ";
        // }
        return j+1;
    }
};