#include<bits/stdc++.h>
using namespace std;

void dfs(int node,int parent,int &timer,vector<int>& tin,vector<int>& low,vector<int>& vis,vector<int>adj[]){
   vis[node]=1;
   tin[node]=low[node]=timer++;
   for(auto it: adj[node]){
    if(it==parent) continue;
    if(!vis[it]){
        dfs(it,node,timer,tin,low,vis,adj);
        low[node]=min(low[node],low[it]);
        if(low[it]>tin[node]){
            cout<<node<<" "<<it<<endl;
        }

    }else{
        low[node]=min(low[node],tin[it]);
    }
   }

}
int main(){
    int V;
    cin>>V;
    vector<int>adj[V];
    int m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> low(V,-1);
    vector<int> tin(V,-1);
    vector<int> vis(V,0);
     timer =0;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,-1,timer,tin,low,vis,adj);
        }
    }
    return 0;

}