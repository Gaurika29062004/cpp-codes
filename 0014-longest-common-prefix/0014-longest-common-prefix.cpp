class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int i=1;i<strs.size();i++){
            if(ans.length()>strs[i].length()){
                ans = ans.substr(0,strs[i].length());
            }
            for(int j=0;j<min(ans.length(),strs[i].length());j++){
                if(ans[j]!=strs[i][j]){
                    ans = ans.substr(0,j);
                    break;
                }
            }
            if(ans.empty()) return ans;
        }
        return ans;
    }
};