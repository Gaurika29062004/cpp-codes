class Solution {
public:
int day(vector<int> &weights , int cap){
    int load = 0;
    int final = 1;
    for(int i=0;i<weights.size();i++){
        if(load + weights[i] > cap){
            final++;
            load = weights[i];
        }
        else load += weights[i];
    }
    return final;
}
    int shipWithinDays(vector<int>& weights, int days) {
    int total = 0;
    int maxx = 0;
    for(int i=0;i<weights.size();i++){
        total += weights[i];
        maxx = max(maxx, weights[i]);
    }
    int low = maxx , high = total;
    while(low<=high){
        int mid = low + (high-low)/2;
        int k = day(weights,mid);
        if(k<=days) high = mid-1;
        else low = mid+1;
    } 
    return low;   
    }
};