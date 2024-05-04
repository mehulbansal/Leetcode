class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0;
        int j = people.size()-1;
        int ans = 0;
        while(i<=j){
            int x = limit;
            if(people[i]+people[j]<=limit){
                i++;
                j--;
                ans++;
            }
            else if(people[j]<=limit){
                j--;
                ans++;
            }
            else if(people[i]<=limit){
                i++;
                ans++;
            }
        }
        return ans;
    }
};