class Solution {
public:
    int height(TreeNode* root){
        if(!root) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int l=height(root->left);
        int h=height(root->right);
        return max(l+h,max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
    }
};