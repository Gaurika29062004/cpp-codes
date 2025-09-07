class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result(n);
        for(int i=0;i<n;i++){
            if(i%2==0) result[i] = i+1;
            else result[i] = -i;
        } 
        if(n%2==1)
        result[n-1] = 0;
     
     return result;  
    }
};