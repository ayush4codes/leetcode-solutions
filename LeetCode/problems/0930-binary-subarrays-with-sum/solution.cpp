class Solution {
public:
    int numSubarraysWithSum(std::vector<int>& nums, int goal) {

        return findAtMost(nums, goal) - findAtMost(nums, goal - 1);
    }

private:
    int findAtMost(const std::vector<int>& arr, int target) {
        if (target < 0) return 0; 
        
        int count = 0, sum = 0;
        int left = 0, right = 0;
        
        while (right < arr.size()) {
            sum += arr[right];
            
            while (left <= right && sum > target) {
                sum -= arr[left]; 
                left++;
            }
            
            count += (right - left + 1);
            right++;
        }
        return count;
    }
};