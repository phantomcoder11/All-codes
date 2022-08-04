bool recursion(TreeNode* root,int B,vector<int>&v){
     if(!root) return false;
     
    
      v.push_back(root->val);
    
      if(root->val==B){
         return true;
     }
     
     if(recursion(root->left,B,v) ||  recursion(root->right,B,v)) return true;
     v.pop_back();
     return false;
     
 }
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>v,ans;
    recursion(A,B,v);
    return v;
}