class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int i=0;
        while(i + 1 < asteroids.size()){
            if(asteroids[i] > 0 && asteroids[i+1] < 0){
                if(abs(asteroids[i]) > abs(asteroids[i+1])){ 
                    asteroids.erase(asteroids.begin() + i + 1);
                    i = max(i-1,0);
                }
                else if(abs(asteroids[i]) < abs(asteroids[i+1])){
                    asteroids.erase(asteroids.begin() + i);
                    i = max(i-1,0);
                }               
                else if(abs(asteroids[i]) == abs(asteroids[i+1])){
                    asteroids.erase(asteroids.begin() + i, asteroids.begin() + i + 2);
                    i = max(i-1,0);
                }
            }
            else{
                i++;
            }
        }
        return asteroids;  
    }
};
