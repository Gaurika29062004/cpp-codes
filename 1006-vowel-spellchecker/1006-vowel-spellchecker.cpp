class Solution {
public:
    string replace_vowel(string s){
        for(auto &it : s){
            if(it == 'a' || it == 'e'||it == 'i' || it == 'o'||it == 'u'){
                it = '*';
            }
        }
        return s;
    }
    string to_lower(string s){
        for(auto &it : s){
            it = tolower(it);
        }
        return s;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        set<string> s;
        unordered_map<string,string> mp1;
        unordered_map<string,string> mp2;
        vector<string> ans;

        for(auto it : wordlist){
            s.insert(it);
            mp1.insert({to_lower(it),it});
            mp2.insert({replace_vowel(to_lower(it)),it});
        }
        for(auto it : queries){
            if(s.find(it)!=s.end()){
               ans.push_back(it); 
            }
            else if(mp1.find(to_lower(it))!=mp1.end()){
                ans.push_back(mp1[to_lower(it)]);
            }
            else if(mp2.find(replace_vowel(to_lower(it)))!=mp1.end()){
                ans.push_back(mp2[replace_vowel(to_lower(it))]);
            }
            else{
                ans.push_back("");
            }
        }
        return ans;
    }
};