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
    int kthSmallest(TreeNode* root, int k) {
        int c = 1;
        int ans = NULL;
        getKth(root, k, c, ans);
        return ans;
    }
    
    void getKth(TreeNode* root, int k, int& c, int& ans){
        if (root == NULL) return;
        getKth(root->left, k, c, ans);
        if (c++ == k) {
            ans = root->val; return;
        } else if (c > k) return;
        getKth(root->right, k, c, ans);
        
    }
};