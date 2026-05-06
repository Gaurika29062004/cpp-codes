class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int,int>mp;
    for(int j=0;j<nums.size();j++){
        if(mp.find(nums[j])!=mp.end()){
            int i = mp[nums[j]];
            if(abs(i-j)<=k) return true;
        }
        mp[nums[j]] = j;
    }
    return false;
    }
};