class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        for (int x : nums) {
            
            while (!st.empty()) {
                int g = gcd(st.back(), x);
                if (g == 1) break;
                x = lcm(st.back(), x);
                st.pop_back();
            }
            st.push_back(x);
        }
        return st;
    }

private:
    long long gcd(long long a, long long b) {
        while (b) {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
    
    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }
};
