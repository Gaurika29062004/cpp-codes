class Solution {
public:
    int countPrimes(int n) {
    if(n==0 || n==1) return 0;
    vector<int>hash(n);
    int count = 0;
    for(int i=2;i<n;i++){
        hash[i] = 1;
    } 
    for(int i=2;i*i<n;i++){
        if(hash[i]==1){
            for(int j=i*i;j<n;j+=i){
                hash[j] = 0;
            }
        }
    }  
    for(auto it : hash){
        if(it == 1) count++;
    }
    return count;
    }
};