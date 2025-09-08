class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int,int> map;
        for(auto it : nums){
            map[it]++;
        }
        struct compare{
            bool operator()(pair<int,int>a , pair<int,int>b){
                return a.second > b.second;
            }
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        for(auto it : map){
            pq.push({it.first,it.second});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
           result.push_back(pq.top().first);
           pq.pop(); 
        }
        return result;
    }
};