class Solution {
public:
    
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long ans = 0;
        vector<int>inc;
        int minm = INT_MAX;
        int maxm = INT_MAX;
        long long a,b;
        for(auto x:nums){
            if((x^k)>=x){
                inc.push_back(x);
                if(maxm>=(x^k)-x){
                    a = x;
                }
                maxm = min(maxm, (x^k)-x);
                ans+=(x^k);
            }
            else{
                
                if(minm>x-(x^k)){
                    b = x;
                }
                minm = min(minm, x-(x^k));
                ans+=x;
            }
        }
        if(inc.size() %2 == 0){
            return ans;
        }
        else{
            if(maxm>=minm){                
                return ans-b+(b^k);
            }
            else{    
                cout<<a<<" "<<(a^k)<<" "<<b<<" "<<(b^k)<<endl;
                return ans+a-(a^k);
            }
        }
        
    }
};