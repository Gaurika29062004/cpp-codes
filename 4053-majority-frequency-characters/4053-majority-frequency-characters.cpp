class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        unordered_map<int, vector<char>> group;
        for (auto& [ch, f] : freq) group[f].push_back(ch);

        int maxSize = 0, maxFreq = 0;
        for (auto& [f, chars] : group) {
            if (chars.size() > maxSize || (chars.size() == maxSize && f > maxFreq)) {
                maxSize = chars.size();
                maxFreq = f;
            }
        }

        string ans;
        for (char c : group[maxFreq]) ans += c;
        return ans;
    }
};