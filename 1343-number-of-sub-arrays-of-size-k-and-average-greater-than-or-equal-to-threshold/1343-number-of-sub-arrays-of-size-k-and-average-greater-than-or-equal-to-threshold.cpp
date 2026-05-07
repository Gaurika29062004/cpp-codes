class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i = 0 , j = k-1;
        int count = 0 , sum = 0;

        for(int x=0;x<k;x++){
            sum += arr[x];
        }
        
        while(j<arr.size()){
            if(sum/k>=threshold) count++;
            sum -= arr[i];
            i++;
            j++;
            if(j<arr.size()) sum += arr[j];
        }
        return count;
    }
};