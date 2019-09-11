//https://leetcode.com/problems/path-sum-iii/submissions/

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
    
    int solve(TreeNode* u, int nowSum, const int &target, multiset < int > &us){
        if(u == NULL) return 0;
        nowSum += u->val;
        int ans = us.count(nowSum-target);
        us.insert(nowSum);
        ans += solve(u->left, nowSum, target, us);
        ans += solve(u->right, nowSum, target, us);
        us.erase(us.find(nowSum));
        return ans;
    }
    
    int pathSum(TreeNode* root, int sum) {
        multiset < int > us;
        us.insert(0);
        return solve(root, 0, sum, us);
    }
};
