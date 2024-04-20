class Solution {
public:
    
    void solve(vector<vector<int>>&land, int i, int j, vector<vector<bool>>&vis, vector<vector<int>>&ans){
        vector<int>grp;
        int m = land.size();
        int n = land[0].size();
        int x = i, y = j;
        while(i<m and land[i][y]==1){
            i++;
        }
        while(j<n and land[x][j]==1){
            j++;
        }
        
        for(int a = x; a<i; a++){
            for(int b = y; b<j; b++){
                vis[a][b] = true;
            }
        }
        grp.push_back(x);
        grp.push_back(y);
        grp.push_back(i-1);
        grp.push_back(j-1);
        ans.push_back(grp);
        
    }
    
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>>ans;
        
        vector<vector<bool>>vis(m, vector<bool>(n, false));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(land[i][j] == 1 and !vis[i][j]){
                    vis[i][j] = true;
                    solve(land, i, j, vis, ans);
                }
            }
        }
        return ans;
    }
};