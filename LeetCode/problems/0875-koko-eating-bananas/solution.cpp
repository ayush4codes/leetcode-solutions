class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 1e9;
        int ans = -1;
        while (left<=right) {
            int mid = (left+right) / 2;
            if (valid(piles,h,mid)) {
                ans = mid; right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return ans;
    }
    bool valid(vector<int> &piles,int hours,int speed) {
        int count = 0;
        for (int x : piles) {
            count  += (x/speed);
            if (x%speed != 0) count++;
            if (count > hours) return false;
        }
        return true;
    }
};