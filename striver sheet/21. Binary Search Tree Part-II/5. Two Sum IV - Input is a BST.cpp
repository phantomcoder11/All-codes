// VERY VERY IMPORTANT
//USE CONCEPT OF BST ITERATOR 
//https://www.youtube.com/watch?v=ssL3sHwPeb4 
class BSTiterator {
    stack<TreeNode*>s;
    bool isReverse;
   
    void pushAll(TreeNode* root){
        while(root){
            s.push(root);
            if(isReverse){
                root=root->right;
            }else{
                root=root->left;
            }
        }
     }
   public:
    BSTiterator(TreeNode* root,bool reverse){
        isReverse=reverse;
        pushAll(root);
    }
   int next(){
       TreeNode* top=s.top();
       s.pop();
       if(isReverse) pushAll(top->left);
       else pushAll(top->right);
       return top->val;
   } 
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTiterator l(root,false);
        BSTiterator r(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k) return true;
            else if(i+j<k) i=l.next();
            else j=r.next();
        }
        return false;
    }
};