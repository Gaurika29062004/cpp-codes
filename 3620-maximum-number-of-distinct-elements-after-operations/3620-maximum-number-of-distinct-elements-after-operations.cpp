class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
       int last_used = INT_MIN;
       int count = 0;
       for(int i=0;i<nums.size();i++){
        int place = max(last_used+1,nums[i]-k);
        if(place <= nums[i]+k){
            count++;
            last_used = place;
        }
       } 
       return count;
    }
};