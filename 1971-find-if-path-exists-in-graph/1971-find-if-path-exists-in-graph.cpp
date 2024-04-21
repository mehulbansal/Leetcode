class Solution {
public:
    void solve(vector<vector<int>>&adj, int source, int dest, bool&ans, vector<bool>&vis){
        if(source == dest) {
            ans=true;
            return;
        }
        
        for(auto x: adj[source]){
            if(!vis[x]){
                vis[x] = true;
                solve(adj, x, dest, ans, vis);
            }
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int dest) {
        vector<vector<int>>adj(n);
        for(int i = 0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        bool ans = false;
        vector<bool>vis(n, false);
        vis[source] = true;
        solve(adj, source, dest, ans, vis);
        return ans;
    }
};