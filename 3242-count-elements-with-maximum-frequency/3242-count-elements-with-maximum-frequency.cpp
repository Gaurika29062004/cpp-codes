class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxfreq = 0;
        unordered_map<int,int> mpp;
        for(auto it : nums){
            mpp[it]++;
            maxfreq = max(maxfreq , mpp[it]);
        } 
        int count = 0;
        for(auto it : mpp){
            if(it.second == maxfreq){
                count += it.second;
            }
        }
        return count;
    }
};