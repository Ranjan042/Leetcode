class Solution {
public:
    bool isSplitPossible(vector<int>& nums, int Lgsum, int k) {
        int count = 1;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] > Lgsum) {
                count++;
                sum = nums[i];

                if (count > k)
                    return false;
            } else {
                sum += nums[i];
            }
        }

        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isSplitPossible(nums, mid, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};