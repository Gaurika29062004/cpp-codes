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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> level;
       if(root == NULL) return level;
        queue<TreeNode*> q;
        TreeNode* node = root;
        q.push(node);
        bool rev = false;
        while(!q.empty()){
            vector<int> ans;
            int size = q.size();
            for(int i=0;i<size;i++){
                node = q.front();
                q.pop();
                ans.push_back(node->val);
                if(node->left!=NULL){
                   q.push(node->left);   
                }
                if(node->right!=NULL){
                   q.push(node->right);   
                }
            }
            if(rev) reverse(ans.begin(),ans.end());
            rev = !rev;

            level.push_back(ans);
            }
        return level;
    }
};