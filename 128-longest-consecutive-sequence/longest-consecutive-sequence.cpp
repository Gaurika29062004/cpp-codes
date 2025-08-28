class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int i=1, maxlen = 0 , len = 0;
        while(i<nums.size()){
            if(nums[i-1]==nums[i]){
                i++;
            }
            else if(nums[i]-nums[i-1] == 1){
                len++;
                maxlen = max(maxlen,len);
                i++;
            }
            else{
                len = 0;
                i++;
            }
        }
    return maxlen+1; 
    }
};