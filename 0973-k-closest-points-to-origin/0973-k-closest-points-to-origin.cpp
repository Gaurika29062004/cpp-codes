class Solution {
public:
    int distance(int x , int y){
        int dist = x*x + y*y;
        return dist;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        priority_queue<pair<int,pair<int,int>>> pq;
        for(auto it : points){
            int ans = distance(it[0],it[1]);
            pq.push({ans,{it[0],it[1]}});

            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            result.push_back({pq.top().second.first , pq.top().second.second});
            pq.pop();
        }
        return result;

    }
};