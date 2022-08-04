//using inorder & preorder O(N) space complexity
class Solution {
public:
    TreeNode* makeBST(vector<int>&preorder,int prestart,int preend,vector<int>&inorder,int instart,int inend,unordered_map<int,int>&m){
        if(prestart>preend || instart>inend) return NULL;
        
        TreeNode* root= new TreeNode(preorder[prestart]);
        int idx= m[preorder[prestart]];
        int len=idx-instart;
        root->left=makeBST(preorder,prestart+1,prestart+len,inorder,instart,idx-1,m);
        root->right=makeBST(preorder,prestart+len+1,preend,inorder,idx+1,inend,m);
            
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder;
        for(auto x:preorder) inorder.push_back(x);
        sort(inorder.begin(),inorder.end());
        unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++) m[inorder[i]]=i;
        return makeBST(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,m);
    }
};
//Using just preorder O(1) space complexity
class Solution {
public:
    TreeNode* makeBST(vector<int>&preorder,int &idx,TreeNode* left,TreeNode* right){
        if(idx==preorder.size() || (left && left->val>preorder[idx]) || (right && right->val<preorder[idx])) return NULL;
        
        TreeNode* root=new TreeNode(preorder[idx++]);
        root->left=makeBST(preorder,idx,left,root);
        root->right=makeBST(preorder,idx,root,right);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0) return NULL;
        int idx=0;
        return makeBST(preorder,idx,NULL,NULL);
    }
};