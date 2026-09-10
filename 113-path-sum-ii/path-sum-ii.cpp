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

    vector<vector<int>>res;
    vector<int>diary;

    void func(TreeNode* root,int sum ,int targetSum){
        if(root == nullptr)return;
        
        sum+= root->val;
        diary.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            if(sum == targetSum){
                res.push_back(diary);
                diary.pop_back();
                return;
            }
        }
        func(root->left,sum,targetSum);
        func(root->right,sum,targetSum);

        diary.pop_back();
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        func(root,0,targetSum);
        return res;
    }
};