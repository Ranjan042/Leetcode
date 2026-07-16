class Solution {
public:
    int calculateDivisionSum(vector<int>& nums,int mid){
        int sum=0;

        for(int i=0;i<nums.size();i++){
           sum += ceil((double)nums[i] / mid);
        }

        return sum;
    }
    int MaxElement(vector<int>&nums){
        int Max=INT_MIN;

        for(int i=0;i<nums.size();i++){
            if(Max<nums[i]){
                Max=nums[i];
            }
        }

        return Max;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=MaxElement(nums);
        int ans=-1;

        while(low<=high){
            int mid = low + (high - low)/2;

            int sum=calculateDivisionSum(nums,mid);

            
            if(sum<=threshold){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        return ans;
    }
};