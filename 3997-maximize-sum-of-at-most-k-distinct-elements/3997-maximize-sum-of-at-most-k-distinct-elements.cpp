class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
      unordered_set<int> s;
      for(auto it : nums){
        s.insert(it);
      }
      vector<int> ans;
      for(auto it : s){
        ans.push_back(it);
      }
      sort(ans.begin(), ans.end(), greater<int>());
      if(k>ans.size()) k = ans.size();
      return vector<int>(ans.begin(),ans.begin()+k);
    }
};