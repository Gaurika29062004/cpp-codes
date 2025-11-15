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
    bool ismirror(TreeNode* p , TreeNode* q){
        if(p==NULL || q==NULL) return p==q;
        bool lr = ismirror(p->left,q->right);
        bool rr = ismirror(p->right,q->left);
        return (lr && rr && p->val == q->val);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return ismirror(root->left,root->right);
    }
};