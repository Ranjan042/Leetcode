class Solution {
public:
    int CalculateBollomflower(vector<int>& bloomDay,int day,int k){
        int NoofBloom=0;
        int NoofadjacentBloom=0;

        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                NoofBloom++;
            }else{
                NoofadjacentBloom+=(NoofBloom/k);
                NoofBloom=0;
            }
        }

         NoofadjacentBloom += (NoofBloom / k);

        return NoofadjacentBloom;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {


       if (1LL * m * k > INT_MAX) {
    return -1;
}
        if (bloomDay.size() < (m * k)) {
            return -1;
        }

        int maxEle = *max_element(bloomDay.begin(), bloomDay.end());

        int low=1;
        int high=maxEle;
        int ans=-1;

          while(low<=high){
            int mid=low+(high-low)/2;
            if(CalculateBollomflower(bloomDay,mid,k)>=m){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
          }
        

        return ans;
    }
};