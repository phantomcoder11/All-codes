#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        // Code here
        vector<int>dis(V,1e8);
        dis[S]=0;
        for(int i=1;i<V;i++){
            for(auto it:adj){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                if(dis[u]!=INT_MAX && dis[u]+wt<dis[v]){
                    dis[v]=dis[u]+wt;
                }
            }
        }
        bool flag=true;
        //NO need for this question because given that no negative weighted cycle
        for(auto it:adj){
            int u=it[0];
                int v=it[1];
                int wt=it[2];
                if(dis[u]!=INT_MAX && dis[u]+wt<dis[v]){
                    flag=false;
                }
        }
        if(flag==false) cout<<"Not Possible";
        return dis;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj;
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1;
            t1.push_back(u);
            t1.push_back(v);
            t1.push_back(w);
            adj.push_back(t1);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.bellman_ford(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends