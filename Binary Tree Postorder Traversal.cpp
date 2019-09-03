//https://leetcode.com/problems/binary-tree-postorder-traversal/

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
    vector<int> postorderTraversal(TreeNode* root) {
        stack < pair < TreeNode*, int > > st;
        if(root != NULL) st.push({root, 0});
        vector < int > ans;
        while (!st.empty()){
            TreeNode* u = st.top().first;
            int pos = st.top().second;
            st.pop();
            if(pos == 0) {
                st.push({u, pos+1});
                if(u->left != NULL) st.push({u->left, 0});
            }
            else if(pos == 1){
                st.push({u, pos+1});
                if(u->right != NULL) st.push({u->right, 0});
            }
            else {
                ans.push_back(u->val);
            }
        }
        return ans;
    }
};
