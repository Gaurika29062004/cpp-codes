class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;
        long long place = 1;
        while(n>0){
            long long digit = n%10;
            if(digit!=0) {
                ans.push_back(digit*place);
            }
            n /= 10;
            place *= 10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};