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
class NodeValue{
    
    public:
    int maxvalue;
    int minvalue;
    int sum;
    bool isBST;
    NodeValue(int min_value,int max_value,int Sum,bool flag){
        this->minvalue=min_value;
        this->maxvalue=max_value;
        this->sum=Sum;
        this->isBST=flag;
    }
    
};

class Solution {
public:
    NodeValue postorder(TreeNode* root,int &ans){
        if(!root) return NodeValue(INT_MAX,INT_MIN,0,true);
        auto l=postorder(root->left,ans);
        auto r=postorder(root->right,ans);
        if(l.isBST && r.isBST && root->val>l.maxvalue && root->val<r.minvalue){
            int res=l.sum+r.sum+root->val;
            ans=max(ans,res);
            return NodeValue(min(l.minvalue,root->val),max(r.maxvalue,root->val),res,true);
        }
        else{
            return NodeValue(0,0,0,false); 
        }
    }
    int maxSumBST(TreeNode* root) {
        int ans=0;
        postorder(root,ans);
        return ans;
    }
};