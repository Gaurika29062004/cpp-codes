class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int count = 0;
        for(int i=0;i<points.size();i++){
            for(int j=0;j<points.size();j++){
                if(i!=j){
                    if(points[i][0] <= points[j][0] && points[i][1] >= points[j][1]){
                        bool blocked = false;
                        for(int k=0;k<points.size();k++){
                            if(k!=i && k!=j){
                                if((min(points[i][0],points[j][0]) <= points[k][0] && 
                                    points[k][0] <= max(points[i][0],points[j][0])) && 
                                    (min(points[i][1],points[j][1]) <= points[k][1] &&
                                    points[k][1] <= max(points[i][1],points[j][1]))){
                                    blocked = true;
                                    break;
                                    }
                                    else{
                                    continue;
                                    }
                                }     
                            }
                        if(!blocked) count++;
                    }
                }
            }
        }
        return count;
    }
};