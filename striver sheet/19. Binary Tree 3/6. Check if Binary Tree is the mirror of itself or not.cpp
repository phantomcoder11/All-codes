class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* root) {
        // code here
        if(!root) return;
        swap(root->right,root->left);
        mirror(root->left);
        mirror(root->right);
    }
};