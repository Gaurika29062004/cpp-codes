class Solution {
public:
    int maxFreqSum(string s) {
    unordered_map<char,int> vowel;
    unordered_map<char,int> cons;
    int result = 0;
    for(char c : s){
        if(c == 'a'|| c == 'e'||c == 'i'||c == 'o'||c == 'u'){
            vowel[c]++;
        }
        else{
            cons[c]++;
        }
    }
    int max1 = 0;
    for(auto it : vowel){
       max1 = max(it.second,max1); 
    }
    int max2 = 0;
    for(auto it : cons){
       max2 = max(it.second,max2); 
    }
    return result = max1 + max2;
    }
};