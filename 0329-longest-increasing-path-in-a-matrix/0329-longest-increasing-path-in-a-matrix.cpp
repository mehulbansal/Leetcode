class Solution {
public:
    int dp[200][200];
    
    int m, n;
    int dfs(vector<vector<int>>& matrix, int i, int j, int curr){
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size() || matrix[i][j]<=curr) return 0;
        if(dp[i][j]!=0) return dp[i][j];
        return dp[i][j] = 1 + max({dfs(matrix, i-1, j, matrix[i][j]),
                                  dfs(matrix, i+1, j, matrix[i][j]),
                                  dfs(matrix, i, j-1, matrix[i][j]),
                                  dfs(matrix, i, j+1, matrix[i][j])});
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                ans = max(ans, dfs(matrix, i, j, -1));
            }
        }
        
        
        return ans;
    }
};