class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> ans;
        map <int,int> mp;

        for(int i=0;i<nums.size();i++){
            int complement=target-nums[i];

            if(mp.find(complement)!=mp.end()){
                ans.push_back(i);
                ans.push_back(mp[complement]);
            }else{
                mp.insert({nums[i],i});
            }
        }

        return ans;
    }
};