/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* t=q.front();
                q.pop();
                if(t){
                   data+=to_string(t->val)+",";
                   q.push(t->left);
                   q.push(t->right);
                }
                else data+="#,";
            }
        }
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="#,") return NULL;
        int i=0;
        string temp="";
        while(data[i]!=','){
            temp+=data[i];
            i++;
        } i++;
        TreeNode* root=new TreeNode(stoi(temp));
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* t=q.front();
            q.pop();
            string left="",right="";
            while(data[i]!=','){
             left+=data[i];
             i++;
            } i++;
            if(left!="#"){
                t->left=new TreeNode(stoi(left));
                q.push(t->left);
            }else t->left=NULL;
            
            
            while(data[i]!=','){
             right+=data[i];
             i++;
            } i++;
            if(right!="#"){
                t->right=new TreeNode(stoi(right));
                q.push(t->right);
            }else t->right=NULL;
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));