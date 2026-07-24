class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> left(n);
        for (int i = 0;i<n;i++) {
            while (st.size() != 0 && arr[i] <= arr[st.top()])  st.pop();
            if (st.size() == 0) left[i] = i+1;
            else left[i] = i-st.top();
            st.push(i);
        }
        st = stack<int>();
        int right = 0;
        long long ans = 0;
        int mod = 1e9+7;
        for (int i = n-1;i>=0;i--) {
            while (st.size() != 0 && arr[i] < arr[st.top()])  st.pop();
            if (st.size() == 0) right = n-i;
            else right = st.top()-i;
            long long mul = ((long long)left[i]*right*arr[i]) %mod;
            ans = (ans + mul) % mod;
            st.push(i);
        }
        return ans;
    }
};