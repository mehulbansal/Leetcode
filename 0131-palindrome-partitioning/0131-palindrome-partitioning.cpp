class Solution {
public:
    
    bool check(string a){
        int i = 0, j=a.length()-1;
        while(i<=j){
            if(a[i]!=a[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }    
    
    void solve(vector<vector<string>>&subset, vector<string>&layer, string s, int idx){
        if(idx == s.length()){
            subset.push_back(layer);
            return;
        }
        for(int i = idx; i<s.length(); i++){
            if(check(s.substr(idx, i-idx+1))){
                layer.push_back(s.substr(idx, i-idx+1));
                solve(subset, layer, s, i+1);
                layer.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>subset;
        vector<string>layer;
        solve(subset, layer, s, 0);
        return subset;
    }
};