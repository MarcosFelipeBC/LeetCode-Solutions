//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:    
    unordered_set < int > us;
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;
        if(us.find(k - root->val) != us.end())
            return true;
        us.insert(root->val);
        return (findTarget(root->left, k) || findTarget(root->right, k));
    }
};
