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
    void helper(TreeNode* root, string pathSoFar, vector<string>& result){
        if(root == NULL) return;

        if(root->left == NULL && root->right == NULL){
            result.push_back(pathSoFar);
            return;
        }
        if(root->left){
        helper(root->left,pathSoFar + "->" + to_string(root->left->val),result);
        }
        if(root->right){
        helper(root->right,pathSoFar+ "->" + to_string(root->right->val),result);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(root == NULL) return result;
        helper(root,to_string(root->val),result);
        return result;
    }
};