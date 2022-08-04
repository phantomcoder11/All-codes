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
// Recursive solution
class Solution {
public:
    void postorder(TreeNode* root,vector<int>&x){
        if(!root) return;

        if(root->left) postorder(root->left,x);
        if(root->right) postorder(root->right,x);
        x.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>x;
        postorder(root,x);
        return x;
    }
};

//USING 2 STACKS
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        if(root==NULL) return v;
        stack<TreeNode*>s1,s2;
        s1.push(root);
        while(!s1.empty()){
            TreeNode* curr = s1.top();
            s1.pop();
            s2.push(curr);
            if(curr->left) s1.push(curr->left);
            if(curr->right) s1.push(curr->right);
        }
        while(s2.size()){
            v.push_back(s2.top()->val);
            s2.pop();
        }
        return v;
    }
};


//USING 1 STACK
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        stack<TreeNode*>s;
        TreeNode* curr = root;
        TreeNode* prev = NULL;
        while(curr!=NULL || !s.empty()){
            if(curr!=NULL){
                s.push(curr);
                curr=curr->left;
            }
            else{
                curr=s.top();
                if(curr->right ==NULL || curr->right == prev){
                 v.push_back(curr->val);
                    s.pop();
                    prev=curr;
                    curr=NULL;
                    
                }
                else
                    curr=curr->right;
            }
        }
        return v;
    }
};
