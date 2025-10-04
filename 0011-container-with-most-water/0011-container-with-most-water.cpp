class Solution {
public:
    int maxArea(vector<int>& height) {
       int i = 0 , j = height.size()-1;
       int ans = 0;
       int final = INT_MIN;
       while(i<j){
        ans = (j-i)*(min(height[i],height[j]));
        final = max(ans,final);
        if(height[i]>height[j]){
        j--;
       }
       else{
        i++;
       }
    }
    return final;   
    }
};