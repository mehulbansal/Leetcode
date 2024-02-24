class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        vector<int>present(3,0);
        int i = 0, j = 0;
        while(j<s.length()){ 
            present[s[j]-'a']++;
            while(present[0]>0 and present[1]>0 and present[2]>0){
                ans+=s.length()-j;
                cout<<ans<<" ";
                present[s[i]-'a']--;
                i++;
                // present[s[i]-'a']++;
                
            }
            // cout<<s[j]<<" ";
            j++;
        }
        return ans;
    }   
};