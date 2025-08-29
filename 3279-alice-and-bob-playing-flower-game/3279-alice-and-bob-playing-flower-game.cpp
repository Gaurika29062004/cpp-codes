class Solution {
public:
    long long flowerGame(int n, int m) {
      int evensN = n/2;
      int oddsN = (n+1)/2;
      int evensM = m/2;
      int oddsM = (m+1)/2;
      return (long long)evensN * oddsM + (long long)evensM * oddsN;
    }
};