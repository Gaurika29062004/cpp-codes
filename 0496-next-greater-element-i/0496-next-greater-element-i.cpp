class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            int idx = 0;
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    idx = j;
                    break;
                }
            }
        int greater = -1;
        for(int k=idx+1;k<nums2.size();k++){
            if(nums2[k]>nums1[i]){
                greater = nums2[k];
                break;
            }
        }
        ans.push_back(greater);
        }
        return ans;
    }
};