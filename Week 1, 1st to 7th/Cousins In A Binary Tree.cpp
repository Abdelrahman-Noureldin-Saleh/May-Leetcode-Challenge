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
    int ans = -1;
    TreeNode* _parent = NULL;
    bool isCousins(TreeNode* root, int x, int y) {
        return mIsCousins(root, x, y, 0, NULL);
    }
    
     bool mIsCousins(TreeNode* root, int x, int y, int depth, TreeNode* parent){
        if (root == NULL) return false;
        if (root->val == x || root->val == y)
            if (ans == -1) ans = depth, _parent = parent;
            else return depth == ans && _parent != parent;
         
        bool left = mIsCousins(root->left, x, y, depth + 1, root);
        bool right = mIsCousins(root->right, x, y, depth + 1, root);
        
        return left || right;
        
    }
};