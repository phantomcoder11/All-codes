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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int prestart,int preend,int instart,int inend, unordered_map<int,int>&m){
     
        if(prestart>preend || instart>inend) return NULL;
        TreeNode* root=new TreeNode(preorder[prestart]);
        int x=m[preorder[prestart]];
        int len=x-instart;
        root->left=build(preorder,inorder,prestart+1,prestart+len,instart,x-1,m);
        root->right=build(preorder,inorder,prestart+len+1,preend,x+1,inend,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        return build(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1,m);
    }
};