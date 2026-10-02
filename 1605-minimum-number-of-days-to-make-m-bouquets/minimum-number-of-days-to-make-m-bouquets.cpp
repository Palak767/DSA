class Solution {
public:
    bool canMake(vector<int>& bloomDay, int m, int k, int mid){
        int count = 0;
        int bouquets = 0;
        for(int bloom : bloomDay){
            if(bloom <= mid){
                count++;
                if(count == k){
                    bouquets++;
                    count = 0;
                }
            }else{
                count = 0;
            }
        }
        return bouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k > bloomDay.size()) return -1;
        int low = std::ranges::min(bloomDay);
        int high = std::ranges::max(bloomDay);
        int ans = high;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(canMake(bloomDay,m,k,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};