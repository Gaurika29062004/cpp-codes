class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum = numBottles;
     while(numBottles >= numExchange){
        int n = numBottles/numExchange;
        sum += n;
        numBottles = n + numBottles%numExchange;
     }  
     return sum; 
    }
};