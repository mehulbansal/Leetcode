class Solution {
public:
    
    void solve(int node, vector<vector<int>>&adj, vector<bool>&vis, long long &ele){
        vis[node] = true;
        ele++;
        for(auto x:adj[node]){
            if(vis[x]==false)
            solve(x, adj, vis, ele);
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(int i = 0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n);
        long long ans = 0;
        int comp = 0;
        
        for(int i = 0; i<n; i++){
            if(vis[i]==false){
                long long ele = 0;
                comp++;
                vis[i] = true;
                solve(i, adj, vis, ele);
                cout<<comp<<" "<<ele<<endl;
                ans+=((n-ele)*ele);
            }
        }
        return ans/2;
    }
};