
 // } Driver Code Ends
class Solution {
    void dfsans(int i,vector<int>adj[],vector<int>&vis,vector<int>&dfs){
        dfs.push_back(i);
        vis[i]=1;
        for(auto x:adj[i]){
            if(!vis[x]){
                dfsans(x,adj,vis,dfs);
                
            }
        }
        return;
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
        vector<int>dfs;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfsans(i,adj,vis,dfs);
            }
        }
        return dfs;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends