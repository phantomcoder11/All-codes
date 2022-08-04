class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        if(!root) return {};
        map<int,int>m;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                Node* node=q.front().first;
                int y=q.front().second;
                q.pop();
                m[y]=node->data;
                if(node->left) q.push({node->left,y-1});
                if(node->right) q.push({node->right,y+1});
            }
        }
        vector<int>ans;
        for(auto x:m){
            ans.push_back(x.second);
        }
        return ans;
    }
};