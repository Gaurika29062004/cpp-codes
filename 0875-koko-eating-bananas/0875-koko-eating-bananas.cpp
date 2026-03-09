class Solution {
public:
    int calmax(vector<int>& piles){
        int maxx = 0;
        for(int i=0;i<piles.size();i++){
            maxx = max(piles[i],maxx);
        }
        return maxx;
    }
    long long speed(int n, vector<int>& piles){
    long long total = 0;
    for(int i = 0; i < piles.size(); i++){
        total += ceil((double)piles[i] / n);
    }
    return total;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxele = calmax(piles);
        long long k = 0;
        int low = 1 , high = maxele;
        while(low<=high){
            int mid = low + (high-low)/2;
            k = speed(mid,piles);
            if(k<=h) high = mid-1;
            else low = mid+1;
        }
    return low;
    }
};