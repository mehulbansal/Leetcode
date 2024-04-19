class Solution {
public:
    
    void solve(vector<vector<char>>&grid, int i, int j, vector<vector<bool>>& vis){
        int m = grid.size();
        int n = grid[0].size();
        if(i<0 or j<0 or i>=m or j>=n or vis[i][j]) return;
        
        if(grid[i][j]=='1' and !vis[i][j]){
            vis[i][j] = true;
            solve(grid, i+1, j, vis);
            solve(grid, i-1, j, vis);
            solve(grid, i, j+1, vis);
            solve(grid, i, j-1, vis);
            
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(), false));
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == '1' and !vis[i][j]){
                    vis[i][j]=true;
                    ans++;
                    solve(grid, i+1, j, vis);
                    solve(grid, i, j+1, vis);
                }
            }
        }
        return ans;
    }
};