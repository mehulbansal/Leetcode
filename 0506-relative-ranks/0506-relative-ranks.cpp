class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int>sscore = score;
        sort(sscore.begin(), sscore.end(), greater<int>());
        vector<string>place = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        map<int, string>mp;
        for(int i = 0; i<sscore.size(); i++){
            if(i<3){
                mp[sscore[i]] = place[i];
            }
            else{
                mp[sscore[i]] = to_string(i+1);
            }
        }
        
        vector<string>ans;
        for(auto x:score){
            ans.push_back(mp[x]);
        }
        return ans;
    }
};