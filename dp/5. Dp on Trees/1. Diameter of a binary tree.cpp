/**
 // https://leetcode.com/problems/diameter-of-binary-tree/
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
    int height(TreeNode* root,int &res){
        if(!root) return 0;
        int l=height(root->left,res);
        int r=height(root->right,res);
        int temp= 1+max(l,r);
        int ans=max(1+l+r,temp);
        res=max(res,ans);
        return temp;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int res=INT_MIN;
        height(root,res);
        return res-1;
    }
};