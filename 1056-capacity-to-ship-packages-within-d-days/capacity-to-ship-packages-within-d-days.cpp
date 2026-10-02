class Solution {
public:
    bool canLoad(vector<int>& weights, int days, int mid){
        int daysNeeded = 1;
        int currentWeight = 0;
        for(int w : weights){
            if(currentWeight + w > mid){
                currentWeight = w;
                daysNeeded++;
            }else{
                currentWeight += w;
            }
        }
        return daysNeeded <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = std::ranges::max(weights);
        int high = std::accumulate(weights.begin(),weights.end(),0);
        int ans = high;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(canLoad(weights,days,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};