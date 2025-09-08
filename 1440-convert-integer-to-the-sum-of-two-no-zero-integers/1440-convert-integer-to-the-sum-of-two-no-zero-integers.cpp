class Solution {
public:
    bool check(int x){
        while(x>0){
            if(x%10 == 0) return false;
            x = x/10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> result;
        for(int i=1;i<n;i++){
            int a = i , b = n-a;
            if(check(a) && check(b)){
                result.push_back(a);
                result.push_back(b);
                break;
            }
        }
        return result;
    }
};