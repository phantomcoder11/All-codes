class Solution {
public:
    void left(Node* root,vector<int>&v){
        if(!root) return;
        if(root->left){
            v.push_back(root->data);
            left(root->left,v);
        }else if(root->right){
            v.push_back(root->data);
            left(root->right,v);
        }
        
    }
    void leaves(Node* root,vector<int>&v){
        if(!root) return;
        if(root->left) leaves(root->left,v);
        if(!root->left && !root->right) v.push_back(root->data);
        if(root->right) leaves(root->right,v);
    }
    void right(Node* root,vector<int>&v){
        if(!root) return;
        if(root->right){
            right(root->right,v);
            v.push_back(root->data);
            
        }else if(root->left){
             right(root->left,v);
             v.push_back(root->data);
             
        }
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>v;
        v.push_back(root->data);
        if(!root->right && !root->left) return v;
        left(root->left,v);
        leaves(root,v);
        right(root->right,v);
        return v;
    }
};