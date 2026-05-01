class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;

        for(int i=0;i<min(k,(int)nums1.size());i++){
            pq.push({nums1[i]+nums2[0],{i,0}});
        }
        while(k-- && !pq.empty()){
            auto top = pq.top();
            pq.pop();

            int a = top.second.first;
            int b = top.second.second;
    
            result.push_back({nums1[a],nums2[b]});
               
            if(b+1 < nums2.size())
            pq.push({nums1[a]+nums2[b+1],{a,b+1}});        
        }
        return result;
    }
};