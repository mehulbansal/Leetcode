class Solution {
public:
    
    
    int solve(int amt, int size, vector<int>&coins, vector<vector<int>>&dp){
        if(amt == 0) return dp[amt][size]=1;
        
        if(amt<0 or size<0 ) return 0;
        if(dp[amt][size]!=-1)return dp[amt][size];
        
        return dp[amt][size] = solve(amt-coins[size], size, coins, dp)+solve(amt, size-1, coins, dp);
    }
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(5002, vector<int>(302,-1));
        return solve(amount, coins.size()-1, coins, dp);
    }
};