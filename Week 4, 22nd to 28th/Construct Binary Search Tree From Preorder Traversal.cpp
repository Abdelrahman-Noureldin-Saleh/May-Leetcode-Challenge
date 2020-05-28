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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size(); if (n == 0) return NULL;
        
        TreeNode* root = new TreeNode(preorder[0]);
        for (int i = 1; i < n; i++)
            mInsert(root, new TreeNode(preorder[i]));
        
        return root;
    }
    
    void mInsert(TreeNode* root, TreeNode* node){
        if (node->val < root->val)
            if (root->left == NULL)
                root->left = node;
            else
                mInsert(root->left, node);
        else if (root->right == NULL)
                root->right = node;
            else
                mInsert(root->right, node);
            
    }
};