class Solution {
    
    public static void solve(char[][] grid, int i, int j, boolean [][] vis){
        int m = grid.length;
        int n = grid[0].length;
        
        if(i<0 || i>=m || j<0 || j>=n || vis[i][j]==true){
            return;
        }
        if(grid[i][j]=='1' && vis[i][j] == false){
            vis[i][j] = true;
            solve(grid, i+1, j, vis);
            solve(grid, i-1, j, vis);
            solve(grid, i, j+1, vis);
            solve(grid, i, j-1, vis);
        }
    }
    
    public int numIslands(char[][] grid) {
        int ans = 0;
        int m = grid.length;
        int n = grid[0].length;
        boolean [][] vis = new boolean[m][n];
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]=='1' && vis[i][j] == false){
                    ans++;
                    vis[i][j] = true;
                    solve(grid, i+1, j, vis);
                    solve(grid, i, j+1, vis);
                }
            }
        }
        return ans;
    }
}