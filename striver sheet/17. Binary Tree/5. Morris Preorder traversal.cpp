 //Moris preorder
class Solution {
public:
      vector<int> preorderTraversal(TreeNode* root) {
       TreeNode* curr=root;
          vector<int>preorder;
          while(curr!=NULL){
              if(curr->left==NULL){
                  preorder.push_back(curr->val);
                  curr=curr->right;
              }else{
                  TreeNode* prev=curr->left;
                  while(prev->right!=NULL && prev->right!=curr){
                      prev=prev->right;
                  }
                  if(prev->right==NULL){
                      
                      prev->right=curr;
                      preorder.push_back(curr->val);
                      curr=curr->left;
                  }else{
                      prev->right=NULL;
                      curr=curr->right;
                  }
              }
          }
          return preorder;
    }
    
    
    
    
};