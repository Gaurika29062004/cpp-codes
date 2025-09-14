class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end()); 
        priority_queue<int, vector<int>, greater<int>> pq; 

        for (int x : s) {
            pq.push(x);
            if (pq.size() > k) pq.pop(); 
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(), ans.end()); 
        return ans;
    }
};
