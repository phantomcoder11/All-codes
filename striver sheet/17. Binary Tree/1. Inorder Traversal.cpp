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
    //recursive
    // void inorder(TreeNode* root, vector<int>&v){
    //     if(!root) return;
    //     if(root->left) inorder(root->left,v);
    //     v.push_back(root->val);
    //     if(root->right) inorder(root->right,v);
    // }
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int>v;
    //     inorder(root,v);
    //     return v;
    // }
    
    //Iterative
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>s;
        vector<int>inorder;
        while(true){
            if(root){
                s.push(root);
                root=root->left;
            }else{
                if(s.empty()) break;
                TreeNode* node=s.top();
                s.pop();
                inorder.push_back(node->val);
                root=node->right;
            }
        }

        return inorder;
    }
    
    
    
    
    
};