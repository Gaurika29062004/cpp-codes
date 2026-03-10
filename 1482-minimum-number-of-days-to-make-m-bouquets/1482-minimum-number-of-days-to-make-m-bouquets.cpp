class Solution {
public:
    int days(vector<int>& bloomDay,int day,int k){
        int count = 0;
        int adj = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                adj++;
                if(adj == k){
                    count++;
                    adj = 0;
                }
            }
            else adj = 0;
            
        }
        return count;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
    long long total = (long long)m*k;
    if(total > bloomDay.size()) return -1;
    int minn = INT_MAX;
    int maxx = 0;
    for(int i=0;i<bloomDay.size();i++){
        minn = min(bloomDay[i],minn);
        maxx = max(bloomDay[i],maxx);
    } 

    int low = minn , high = maxx;
    while(low<=high){
        int mid = low + (high-low)/2;
        int ans = days(bloomDay,mid,k);
        
        if(ans >= m) high = mid-1;
        else low = mid+1;
    } 
    return low; 
    }
};