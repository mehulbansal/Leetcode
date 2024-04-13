class Solution {
public:
    vector<int> nextSmaller(vector<int>& h){
        int n = h.size();
        stack<int>st;
        st.push(-1);
        vector<int>ans(n);
        for(int i = n-1; i>=0; i--){
            while(st.top()!=-1 and h[st.top()]>=h[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmaller(vector<int>& h){
        int n = h.size();
        stack<int>st;
        st.push(-1);
        vector<int>ans(n);
        for(int i = 0; i<n; i++){
            while(st.top()!=-1 and h[st.top()]>=h[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>next = nextSmaller(heights);
        vector<int>prev = prevSmaller(heights);
        int n = heights.size();
        long long ans = INT_MIN;
        for(int i = 0; i<n; i++){
            if(next[i]==-1) next[i]=n;
            long long z = (next[i]-prev[i]-1)*heights[i];
            ans = max(ans, z);
        }
        return ans;
    }
};