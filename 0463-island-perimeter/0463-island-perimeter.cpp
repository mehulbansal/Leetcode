class Solution {
public:
    
    int solve(vector<vector<int>>&grid, int i, int j){
        int ans = 0;
        if(i==0){
            ans++;
        }
        if(j == 0){
            ans++;   
        }
        if(i == grid.size()-1){
            ans++;
        }
        if(j == grid[0].size() -1) ans++;
        if(j>0 and grid[i][j-1] == 0){
            ans++;
        }
        if(j<grid[0].size()-1 and grid[i][j+1] == 0){
            ans++;
        }
        if(i>0 and grid[i-1][j] == 0){
            ans++;
        }
        if(i<grid.size()-1 and grid[i+1][j] == 0){
            ans++;
        }
        return ans;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0;j<grid[0].size(); j++){
                if(grid[i][j]==1)
                ans+=solve(grid, i, j);
            }
        }
        return ans;
    }
};