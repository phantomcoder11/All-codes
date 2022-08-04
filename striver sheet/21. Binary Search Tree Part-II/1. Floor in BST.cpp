// SAme as finding the predecessor in BST
int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    TreeNode<int>* floor=NULL;
    while(root){
        if(root->val>X){
            root=root->left;
        }else{
            floor=root;
            root=root->right;
        }
    }
    return floor->val;
}
