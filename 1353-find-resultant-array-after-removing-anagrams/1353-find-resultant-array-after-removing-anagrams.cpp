class Solution {
public:
    bool isAnagram(string &a , string &b){
        if(a.size()!=b.size()) return false;
        map<char,int> mp;
        for(char c : a) mp[c]++;
        for(char c : b) mp[c]--;
        for(auto it : mp){
            if(it.second!=0) return false;
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> s;
        s.push_back(words[0]);
        for(int i=1;i<words.size();i++){
            if(!s.empty() && !isAnagram(words[i-1],words[i])){
                s.push_back(words[i]);
            }
        } 
        return s;  
    }
};