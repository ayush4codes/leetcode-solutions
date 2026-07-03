class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for (int x : nums) set.insert(x);
        int ans = 0;
        for (int x : set) {
            if (!set.count(x-1)) {
                int curr = 0;
                while (set.count(x)) {
                    x++;
                    curr++;
                }
                ans = max(ans,curr);
            }
        }
        return ans;
    }
};