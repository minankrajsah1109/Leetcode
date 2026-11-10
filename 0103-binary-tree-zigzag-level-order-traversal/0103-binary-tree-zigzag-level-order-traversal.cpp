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
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }
    void nthLevel(TreeNode* root, int curr, int level, vector<int>& v){
        if(root == NULL) return; // base case
        if(curr == level){
            v.push_back(root->val); // root
            return;
        }
        if(level % 2 == 1){
            nthLevel(root->left, curr+1, level, v); // left
        nthLevel(root->right, curr+1, level, v); // right
        }
        if(level % 2 == 0){
            nthLevel(root->right, curr+1, level, v); // right
            nthLevel(root->left, curr+1, level, v); // left
        }
    }
    void levelOrderZigZag(TreeNode* root, vector<vector<int>>& ans){
        int n = levels(root);
        for(int i = 1; i <= n; i++){
            vector<int> v;
            nthLevel(root, 1, i, v);
            ans.push_back(v);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelOrderZigZag(root, ans);
        return ans;
    }
};