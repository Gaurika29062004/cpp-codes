class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        for(int i=0;i<n;i++){
            int j = 0;
            j = i + nums[i];
            j = ((j % n) + n) % n;
            result[i] = nums[j];
        }
        return result;  
    }
};