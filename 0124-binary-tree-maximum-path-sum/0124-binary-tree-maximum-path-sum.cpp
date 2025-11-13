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
    int maxans = INT_MIN;
    int sum(TreeNode* root){
        if(root == NULL) return 0;
        int lh = sum(root->left);
        int rh = sum(root->right);
        maxans = max(maxans,root->val + max(0,lh) + max(0,rh));
        return root->val + max(0,max(lh,rh));
    }
    int maxPathSum(TreeNode* root) {
        sum(root);
        return maxans;
    }
};