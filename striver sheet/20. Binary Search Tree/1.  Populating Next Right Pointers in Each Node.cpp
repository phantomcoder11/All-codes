/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
//USing BFS 
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        //WE would be going with level order traversal
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            Node* temp;
            for(int i=0;i<n;i++){
                Node* x=q.front();
                q.pop();
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
                if(i==0){
                    temp=x;
                }else{
                    temp->next=x;
                    temp=temp->next;
                }
            }
 // temp->next=NULL;
        }
        return root;
    }
};



//USing DFS
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        if(root->left){
            root->left->next=root->right;
            if(root->next) root->right->next=root->next->left;
            connect(root->left);
            connect(root->right);
        }
        return root;
    }
};

//USING BFS WITH O(1) SPACE
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        Node* temp=root;
        while(root->left){
            Node* curr=root;
            while(curr){
                curr->left->next=curr->right;
                if(curr->next) curr->right->next=curr->next->left;
                curr=curr->next;
            }
            root=root->left;
        }
        return temp;
    }
};