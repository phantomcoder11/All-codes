#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    bool bfs(int node, vector<int>&color,vector<int>adj[]){
        queue<int>q;
        q.push(node);
        color[node]=1;
        while(!q.empty()){
            int front =q.front();
            q.pop();
            for(auto x:adj[front]){
                if(color[x]==-1){
                    q.push(x);
                    color[x]=1-color[front];
                }else if(color[x]==color[front]){
                    return false;
                }
            }
        }
        return true;
    }
    bool dfs(int node, vector<int>&color,vector<int>adj[]){
        if(color[node]==-1) color[node]=1;
        for(auto x:adj[node]){
            if(color[x]==-1){
             color[x]=1-color[node];
                if(!dfs(x,color,adj)) return false;
            } else if(color[x]==color[node]) return false;
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>color(V,-1);
	    
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(!dfs(i,color,adj))
	            return false;
	        }
	    }
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends