class Solution {
public:
    int firstMatchingIndex(string s) {
    int start = 0 , end = s.size()-1;
    while(start<=end){
        if(s[start]==s[end]){
            return start;
            break; 
        }
        start++;
        end--;
    }
    return -1;    
    }
};