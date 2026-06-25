class Solution {
public:
    int bs(vector<int>& nums,int target) {
        int l = 0, r = nums.size() -1, ans = r+1;
        while (l <= r) {
            int mid = (l+r) / 2;
            if (nums[mid] >= target) {
                ans = mid; r = mid-1;
            } else {
                l =mid+1;
            }
         }
         return ans;
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted;
        vector<int> answer(n,0);
        for (int i = n-1;i>=0;i--) {
            int pos = bs(sorted,nums[i]);
            answer[i] = pos;
            sorted.insert(sorted.begin()+pos,nums[i]);
            // for (int x : sorted) cout << x << " ";
            // cout << " " << endl;
        }
        return answer;
    }
};