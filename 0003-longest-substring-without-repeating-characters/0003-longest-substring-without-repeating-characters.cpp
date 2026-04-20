class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int i=0, j=0 , len=0;
        while(j<s.size() && i<=j){
            if(mp.find(s[j]) != mp.end() && mp[s[j]]>=i){
                i = max(i,mp[s[j]]+1);
            }
            len = max(len,j-i+1);
            mp[s[j]]=j;
            j++;
        }
        return len;
    }
};