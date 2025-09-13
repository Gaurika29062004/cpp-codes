class Solution {
public:
    int maxFreqSum(string s) {
    unordered_map<char,int> freq;
    int maxV = 0 , maxC = 0;
    for(char c : s) freq[c]++;
    for(auto it : freq){
        if(it.first == 'a'|| it.first == 'e'||it.first == 'i'||it.first == 'o'||it.first == 'u'){
            maxV = max(maxV,it.second);
        }
        else{
             maxC = max(maxC,it.second);
        }
    }
    return maxV + maxC;
    }
};