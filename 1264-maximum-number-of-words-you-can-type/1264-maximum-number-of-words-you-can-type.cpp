class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
       unordered_set<char> s(brokenLetters.begin(),brokenLetters.end());
       int count = 0;
       bool found = true;
        for(auto it : text){
            if(it == ' '){
                if(found) count++;
                found = true;
            }
            else if(s.find(it)!=s.end()){
            found = false; 
            }
        }
        if(found) count++;
       return count;
    }
};