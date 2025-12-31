class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int len = 0;
        int i = 0 , j=0;
        while(i<s.size()){
            if(mp.find(s[i])!=mp.end()){
                j = max(j,mp[s[i]]+1);
            }
            mp[s[i]] = i;
            len = max(len,i-j+1);
            i++;
        }
        return len;
    }
};