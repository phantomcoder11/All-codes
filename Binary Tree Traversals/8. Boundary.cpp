class Solution {
public:
    void left(Node* root,vector<int>&ans){
        if(!root) return;
        if(root->left){
            ans.push_back(root->data);
            left(root->left,ans);
        }else if(root->right){
            ans.push_back(root->data);
            left(root->right,ans);
        }
    }
    void inorder(Node* root,vector<int>&ans){
        if(!root) return;
        if(root->left) inorder(root->left,ans);
        if(!root->left && !root->right) ans.push_back(root->data);
        if(root->right) inorder(root->right,ans);
    }
    void right(Node* root,vector<int>&ans){
        if(!root) return;
        if(root->right){
            right(root->right,ans);
            ans.push_back(root->data);
        }else if(root->left){
            right(root->left,ans);
            ans.push_back(root->data);
        }
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        if(!root) return {};
        if(!root->left && !root->right) return {root->data};
        vector<int>ans;
       
        ans.push_back(root->data);
        left(root->left,ans);
        inorder(root,ans);
        right(root->right,ans);
        return ans;
    }
};