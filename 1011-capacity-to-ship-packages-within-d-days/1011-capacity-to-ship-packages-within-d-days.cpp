class Solution {
public:
    int calculateRequiredDay(vector<int>& weights, int weight) {
        int day = 1;
        int currentWeight = 0;

        for (int i = 0; i < weights.size(); i++) {

            if(weights[i]>weight){
                return INT_MAX-1;
            }
            currentWeight += weights[i];

            if (currentWeight > weight) {
                day++;
                currentWeight = weights[i];
            }
        }

        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 1;
        int sum = accumulate(weights.begin(), weights.end(), 0);
        int high = sum;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int usedDay = calculateRequiredDay(weights, mid);

            if (usedDay <= days) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};