class Solution {
public:
    bool bfschecker(int i,vector<int>&color,vector<vector<int>>&graph){
        queue<int>q;
            q.push(i);
            color[i]=0;
            while(!q.empty()){
                int front=q.front();
                q.pop();
                for(auto x:graph[front]){
                    if(color[x]==-1){
                        q.push(x);
                        color[x]=1-color[front];
                    }else if(color[x]==color[front])  return false;
                }
                
            }
        return true;
    }
    bool dfschecker(int i,vector<int>&color,vector<vector<int>>& graph){
        if(color[i]==-1) color[i]=0;
        for(auto x:graph[i]){
            if(color[x]==-1){
                color[x]=1-color[i];
                  
                if(!dfschecker(x,color,graph)) return false;
            }else if(color[x]==color[i]){
              
                return false;
            } 
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(!dfschecker(i,color,graph)) return false;
            }
            
        }
        return true;
    }
};