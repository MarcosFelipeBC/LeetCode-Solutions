//https://leetcode.com/problems/maximum-binary-tree/

// * Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        vector < int > left, right;
        int mx = 0;
        for (int i=1; i<(int)nums.size(); i++){
            if(nums[i] > nums[mx]) mx = i;
        }
        for (int i=0; i<mx; i++) left.push_back(nums[i]);
        for (int i=mx+1; i<(int)nums.size(); i++) right.push_back(nums[i]);
        TreeNode *root = new TreeNode(nums[mx]);
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        return root;
    }
};
