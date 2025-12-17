class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> startend(n,0);
        for(int i=0;i<n;i++){
            startend[i] = min(n,i+nums[i]);
        }    
        int jumps = 0;
        int maxend = 0;
        int currend = 0;
        for(int i=0;i<n;i++){
            if(i>maxend){
                return -1;
            }
            if(i>currend){
                jumps++;
                currend = maxend;
            }
            maxend = max(maxend,startend[i]);
        }
        return jumps;
    }
};