class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        map<int,int>m;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                int y=q.front().second;
                Node* node=q.front().first;
                q.pop();
                if(m.find(y)==m.end()){
                    m[y]=node->data;
                }
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
