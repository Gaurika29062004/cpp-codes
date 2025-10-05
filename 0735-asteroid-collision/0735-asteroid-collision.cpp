class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
      stack<int> s;
      for(int it : asteroids){
        bool destroyed = false;
        while(!s.empty() && it < 0 && s.top()>0){
            if(abs(s.top()) < abs(it)){
                s.pop();
                continue;
            }
            else if(abs(s.top()) == abs(it)){
                s.pop();
            }
            destroyed = true;
            break;
        }
        if(!destroyed) s.push(it);
    }
    int n = s.size();
    vector<int> res(n);
    for(int i = s.size()-1 ; i>=0 ; i--){
        res[i] = s.top();
        s.pop();
    }
    return res;
    }
};