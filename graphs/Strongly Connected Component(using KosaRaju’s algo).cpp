#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	void dfs(int node,vector<int>&vis,vector<int>adj[],stack<int>&s){
	    vis[node]=1;
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            dfs(it,vis,adj,s);
	        }
	    }
	    s.push(node);
	}
	void revdfs(int node, vector<int>&vis,vector<int>rev[]){
	    vis[node]=1;
	    for(auto it:rev[node]){
	        if(!vis[it]){
	            revdfs(it,vis,rev);
	        }
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int>vis(V,0);
        stack<int>s;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,s);
            }
        }
        vector<int>rev[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto x:adj[i]){
                rev[x].push_back(i);
            }
        }
        int count=0;
        while(!s.empty()){
            if(!vis[s.top()]){
                revdfs(s.top(),vis,rev);
                count++;
            }
            s.pop();
        }
        return count;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends