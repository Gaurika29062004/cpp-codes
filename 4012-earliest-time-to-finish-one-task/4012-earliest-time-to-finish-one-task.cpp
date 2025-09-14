class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int result = INT_MAX;
        for(auto it : tasks){
            int time = it[0]+it[1];
            result = min(time,result);
        }
        return result;
    }
};