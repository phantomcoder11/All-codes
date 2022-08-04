class Solution {
public:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,int poststart,int postend,int instart,int inend, unordered_map<int,int>&m){
        if(poststart<postend || instart>inend) return NULL;
        TreeNode* root= new TreeNode(postorder[poststart]);
        int x=m[postorder[poststart]];
        int len=inend-x;
        root->right=build(inorder,postorder,poststart-1,poststart-len,x+1,inend,m);
        root->left=build(inorder,postorder,poststart-len-1,postend,instart,x-1,m);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++) m[inorder[i]]=i; 
        return build(inorder,postorder,postorder.size()-1,0,0,inorder.size()-1,m);
    