class Solution {
public:
    int firstUniqChar(string s) {
        if(s.empty()) return -1;
        if(s.size()==1) return 0;
    unordered_map<char,pair<int,int>>mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]].first++;
        mp[s[i]].second = i;
    }
    int index = INT_MAX;
    for(auto it : mp){
        if(it.second.first == 1){
            index = min(index,it.second.second);
        }
    }
    return index == INT_MAX ? -1 : index;
    }
};