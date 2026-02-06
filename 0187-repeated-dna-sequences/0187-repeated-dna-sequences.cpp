class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
    vector<string> ans;
    if(s.size()<10) return ans;
    unordered_map<string,int> mp;
    for(int i=0;i+9<s.size();i++){
        string a = s.substr(i,10);
        mp[a]++;
        if(mp[a]==2) ans.push_back(a);
    }
    return ans;
    }
};