class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result(n);
     if(n%2==0){
        for(int i=0;i<n;i++){
            if(i%2==0) result[i] = i+1;
            else result[i] = -i;
        }
     } 
     else if(n%2==1){
        for(int i=0;i<n-1;i++){
            if(i%2==0) result[i] = i+1;
            else result[i] = -i;
        }
        result[n-1] = 0;
     }
     return result;  
    }
};