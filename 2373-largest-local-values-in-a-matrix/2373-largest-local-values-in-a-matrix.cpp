class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>ans;
        for(int i = 1; i<m-1; i++){
            vector<int>p;
            for(int j = 1; j<n-1; j++){
                int z = max({grid[i-1][j-1], grid[i][j-1], grid[i+1][j-1],
                            grid[i-1][j], grid[i][j], grid[i+1][j],
                            grid[i-1][j+1], grid[i][j+1], grid[i+1][j+1]});
                p.push_back(z);
            }
            ans.push_back(p);
        }
        return ans;
    }
};