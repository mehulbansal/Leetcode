class Solution {
public:
    vector<int>prevSmaller(vector<int>& arr){
        stack<int>st;
        st.push(-1);
        int n = arr.size();
        vector<int>ans(n);
        for(int i = 0; i<n; i++){
            while(st.top()!=-1 and arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>nextSmaller(vector<int>& arr){
        stack<int>st;
        st.push(-1);
        int n = arr.size();
        vector<int>ans(n);
        for(int i = n-1; i>=0; i--){
            while(st.top()!=-1 and arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>matrix1(m, vector<int>(n));
        for(int j = 0; j<n; j++){
            matrix1[0][j] = int(matrix[0][j]-'0');
        }
        for(int i = 1; i<m; i++){
            for(int j = 0; j<n; j++){
                if(matrix[i][j]=='1'){
                    matrix1[i][j]=1+matrix1[i-1][j];
                    // matrix[i][j]+=int(matrix[i-1][j])-48;
                }
                else{
                    matrix1[i][j]=int(matrix[i][j]-'0');
                }
            }
        }   
        int ans = INT_MIN;
        for(int i = 0; i<m; i++){
            vector<int>next = nextSmaller(matrix1[i]);
            vector<int>prev = prevSmaller(matrix1[i]);
            for(int j = 0; j<n; j++){
                cout<<(matrix1[i][j])<<" ";
                // cout<<next[j]<<" ";
                
                if(next[j]==-1)next[j] = n;
                // int x = int(matrix[i][j])-48;
                ans = max(ans, matrix1[i][j]*(next[j]-prev[j]-1));
                
                // cout<<(next[j]-prev[j]-1)*(x)<<" ";
            }
            cout<<endl;
        }   
        
        
        return ans;
    }
};