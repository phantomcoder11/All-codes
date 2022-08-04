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
// RECURSIVE
// class Solution {
// public:
//     void preorder(TreeNode* root, vector<int>&x){
//         if(!root) return;
//         x.push_back(root->val);
//         if(root->left) preorder(root->left,x);
//         if(root->right) preorder(root->right,x);
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int>x;
//         preorder(root,x);
//         return x;
//     }
// };
// ITERATIVE
class Solution {
public:

    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*>s;
        vector<int>preorder;
        while(true){
            if(root){
              preorder.push_back(root->val);
              s.push(root);
              root=root->left;
            }else{
                if(s.empty()) break;
                TreeNode* node=s.top();
                s.pop();
                root=node->right;
            }
        }
        return preorder;
    }
};