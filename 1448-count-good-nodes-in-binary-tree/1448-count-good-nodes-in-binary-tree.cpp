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
    int compare(TreeNode* root,int maxsofar){
        if(root == NULL) return 0;
        int count = 0;
        if(root->val >= maxsofar) count++;
        maxsofar = max(maxsofar,root->val);
        int lh = compare(root->left,maxsofar);
        int rh = compare(root->right,maxsofar);
        return count + lh + rh;
    }
    int goodNodes(TreeNode* root) {
        return compare(root,root->val);
    }
};