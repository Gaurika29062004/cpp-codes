class Solution {
public:
    int func(int idx ,vector<int> &nums , vector<int> &dp){
        if(idx == 0) return nums[0];
        if(idx < 0) return 0;
        if(dp[idx]!=-1) return dp[idx];

        int pick = nums[idx] + func(idx-2,nums,dp);
        int not_pick = func(idx-1,nums,dp);

        int maxcost = max(pick,not_pick);
        return dp[idx] = maxcost;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return func(n-1,nums,dp);
    }
};