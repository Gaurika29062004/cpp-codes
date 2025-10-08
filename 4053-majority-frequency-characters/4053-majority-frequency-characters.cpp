class Solution {
public:
    string majorityFrequencyGroup(string s) {
    unordered_map<char,int> mp1;
    int group = 0;
    int j = 0;
    string ans = "";
    for(auto it : s){
        mp1[it]++;
    }
    unordered_map<int,int> mp2;
    for(auto it : mp1){
        mp2[it.second]++;
    }
    for(auto it : mp2){
        if(it.second > group){
            group = max(group,it.second);
            j = it.first;
        }
        else if(it.second == group && it.first > j){
            j = it.first;
        }
    }
    for(auto it : mp1){
        if(it.second == j){
            ans += it.first;
        }
    }
    return ans;
    
    }
};