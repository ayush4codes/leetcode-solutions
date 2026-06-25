class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int max1 = INT_MIN;
            int n = nums.size();
            int curr = 0;
            for(int i=0;i<n;i++){
                curr = max(curr+nums[i],nums[i]);
                max1=max(curr,max1);
            }
            return max1;
        }
    };