/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root,unordered_map<int,int>&mp){
        if(root == NULL) return 0;  
        int lh = helper(root->left,mp);
        int rh = helper(root->right,mp);
        int sum = root->val + lh + rh;
        mp[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        unordered_map<int,int>mp;
        helper(root,mp);
        int maxfreq = 0;
        for(auto it : mp){
            maxfreq = max(maxfreq,it.second);
        }
        for(auto it : mp){
            if(it.second == maxfreq){
                ans.push_back(it.first);
            }
        }
    return ans;
    }
};