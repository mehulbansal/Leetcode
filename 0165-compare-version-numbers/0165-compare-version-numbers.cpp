class Solution {
public:
    
    vector<string>split(string v){
        vector<string>ans;
        int start = 0;
        int end = 0;
        for(int i = 0; i<v.size(); i++){
            if(v[i]=='.'){
                end = i;
                ans.push_back(v.substr(start, end-start));
                start = i+1;
            }
            else if(i == v.size()-1){
                ans.push_back(v.substr(start, i-start+1));
            }
        }
        
        return ans;
    }
    
    int compareVersion(string version1, string version2) {
        vector<string>v1 = split(version1);
        vector<string>v2 = split(version2);
        while(v1.size()<v2.size()){
            v1.push_back("0");
        }
        while(v1.size()>v2.size()){
            v2.push_back("0");
        }
        
        for(int i = 0; i<v1.size(); i++){
            if(stoi(v1[i])<stoi(v2[i]))return -1;
            if(stoi(v1[i])>stoi(v2[i]))return 1;
        }
        return 0;
    }
};