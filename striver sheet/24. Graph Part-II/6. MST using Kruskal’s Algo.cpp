#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    //Solving by Brute Force
    // int spanningTree(int V, vector<vector<int>> adj[])
    // {
    //     // code here
    //     int key[V];
    //     bool mst[V];
    //     for(int i=0;i<V;i++){
    //         key[i]=INT_MAX;
    //         mst[i]=false;
    //     }
    //     key[0]=0;
    //     for(int i=0;i<V;i++){
    //         int mini=INT_MAX,u;
            
    //         for(int i=0;i<V;i++){
    //             if(mst[i]==false && key[i]<mini){
    //                 mini=key[i];
    //                 u=i;
    //             }
    //         }
            
    //         mst[u]=true;
    //         for(auto x:adj[u]){
              
    //             if(mst[x[0]]==false && x[1]<key[x[0]]){
                   
    //                 key[x[0]]=x[1];
    //             }
    //         }
    //     }
    //     int sum=0;
    //     for(int i=0;i<V;i++){
          
    //         if(key[i]!=INT_MAX) sum+=key[i];
    //     }
    //     return sum;
    // }
    //Solving by using priority queue Prim's Algo
    // int spanningTree(int V, vector<vector<int>> adj[]){
    //     bool mst[V];
    //     int key[V];
    //     for(int i=0;i<V;i++){
    //         key[i]=INT_MAX;
    //         mst[i]=false;
    //     }
    //     key[0]=0;
    //     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    //     q.push({0,0});
    //     while(!q.empty()){
            
           
    //         int u=q.top().second;
    //         q.pop();
    //         mst[u]=true;
    //         for(auto x:adj[u]){
    //             if(mst[x[0]]==false && x[1]<key[x[0]]){
    //                 key[x[0]]=x[1];
    //                 q.push({key[x[0]],x[0]});
    //             }
    //         }
    //     }
    //     int sum=0;
    //     for(int i=0;i<V;i++){
          
    //         if(key[i]!=INT_MAX) sum+=key[i];
    //     }
    //     return sum;
    // }
    // By Kruskal’s Algo
    int spanningTree(int V, vector<vector<int>> adj[]){
        int parent[V];
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        int rank[V]={ 0 }; 
        vector<vector<int>>edges;
      
        for(int i=0;i<V;i++){
           for(auto x:adj[i]){
               edges.push_back({x[1],i,x[0]});
           }
            // edges.push_back({adj[i][2],adj[i][0],adj[i][1]});
        }
        int ans=0;

        sort(edges.begin(),edges.end());
        for(auto x:edges){
            if(findParent(x[1],parent)!=findParent(x[2],parent)){
                ans+=x[0];
                unionn(x[1],x[2],parent,rank);
            }
        }
        return ans;
    }
    int findParent(int node,int parent[]){
        if(node==parent[node]) return node;
        return parent[node]=findParent(parent[node],parent);
    }
    void unionn(int u,int v,int parent[],int rank[]){
        u=findParent(u,parent);
        v=findParent(v,parent);
        if(rank[u]<rank[v]){
            parent[u]=v;
        }else if(rank[v]<rank[u]){
            parent[v]=u;
        }else{
            parent[u]=v;
            rank[v]++;
        }
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends