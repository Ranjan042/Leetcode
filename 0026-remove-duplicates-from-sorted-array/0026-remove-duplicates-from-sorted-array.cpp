class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
 if (nums.empty()) return 0;

        int k = 0;
        int i = 0;
        int j = 1;

        while (j < nums.size()) {
            if (nums[i] == nums[j]) {
                j++;
            } else {
                nums[k] = nums[i];
                k++;
                i = j;
                j++;
            }
        }

        nums[k] = nums[i];

        return k + 1;
    }
};