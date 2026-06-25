class Solution {
    vector<int> dp;
    int n;
public:
    int jump(vector<int>& nums) {
        n = nums.size();
        dp.resize(n,-1);
        return find(nums,0);
    }
    int find(vector<int>& nums,int i) {
        if (i == n-1) return 0;
        if (dp[i] != -1) return dp[i];
        int mini = INT_MAX/2;
        for (int j = i+1;j<= min(n-1,i+nums[i]);j++) {
            int curr = find(nums,j);
            mini = min(curr+1,mini);
        }
        return  dp[i] = mini;
    }
};