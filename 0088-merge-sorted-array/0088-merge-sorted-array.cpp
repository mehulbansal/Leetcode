class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j=n-1;
        if(i<0){
            nums1=nums2;
            return;
        }
        for(int x = m+n-1; x>=0; x--){
            if(i<0|| j<0) break;
            if(nums1[i]>=nums2[j]){
                nums1[x]=nums1[i];
                i--;
            }
            else{
                nums1[x]=nums2[j];
                j--;
            }
        }
        if(i < 0){
            for(int x = 0; x<=j; x++){
                nums1[x] = nums2[x];
            }
        }
        return ;
    }
};