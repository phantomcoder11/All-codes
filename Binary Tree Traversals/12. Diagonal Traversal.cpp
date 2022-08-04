vector<int> diagonal(Node *root)
{
   // your code here
   if(!root) return {};
   vector<int>ans;
   queue<Node*>q;
   q.push(root);
   while(!q.empty()){
       Node* node=q.front();
       q.pop();
       if(node->left) q.push(node->left);
       ans.push_back(node->data);
       while(node->right){
           node=node->right;
           if(node->left) q.push(node->left);
           ans.push_back(node->data);
       }
   }
   return ans;
}