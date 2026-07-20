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
    int res = -1;

    int func(TreeNode* root){
        if(root == nullptr)
            return 0;
        int left = func(root->left);
        int right = func(root->right);
        
        int sum = left + right;

        res  = max(res,sum);
        return 1 + max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        func(root);
        return res;
        
    }
};