class Solution {
public:
    int compare(int a, int b){
        if(a > b) return 1;
        if(a < b) return -1;
        return 0;
    }

    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 1;

        int i = 0, len = 1;
        int prev = 0;

        for(int j = 1; j < n; j++){
            int curr = compare(arr[j], arr[j-1]);

            if(curr != 0){
                len = max(len, 2);
            }

            if(curr == 0){
                i = j;
                prev = 0;
            }
            else if(prev * curr == -1){
                len = max(len, j - i + 1);
                prev = curr;
            }
            else{
                i = j - 1;
                prev = curr;
            }
        }

        return len;
    }
};