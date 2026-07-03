class Solution {
    vector<int> dp;
    int n;
public:
    bool canJump(vector<int>& nums) {
        n = nums.size();
        dp.resize(n,-1);
        return find(nums,0);
    }
    bool find(vector<int>& nums,int i) {
        if (i == nums.size()-1) return true;
        if (dp[i] != -1) return dp[i];
        for (int j = i+1; j<= min(n-1,i+nums[i]);j++) {
            bool check = find(nums,j);
            if (check) {
                dp[i] = 1;
                return true;
            }
        }
        dp[i] = 0;
        return false;
    }
};