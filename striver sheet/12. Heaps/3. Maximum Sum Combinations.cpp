vector<int> Solution::solve(vector<int> &a, vector<int> &b, int c) {
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    priority_queue<pair<int,pair<int,int>>>q;
    set<pair<int,int>>s;
    int n=a.size();
    q.push({a[n-1]+b[n-1],{n-1,n-1}});
    s.insert({n-1,n-1});
    vector<int>ans;
    while(q.size() && c--){
        pair<int,pair<int,int>>x=q.top();
        q.pop();
       
        int i=x.second.first;
        int j=x.second.second;
        ans.push_back(a[i]+b[j]);
        if(i>0){
            if(s.find({i-1,j})==s.end()){
                q.push({a[i-1]+b[j],{i-1,j}});
                s.insert({i-1,j});
            }
        }
        if(j>0){
            if(s.find({i,j-1})==s.end()){
                q.push({a[i]+b[j-1],{i,j-1}});
                s.insert({i,j-1});
            }
        }
        if(j>0 && i>0){
            if(s.find({i-1,j-1})==s.end()){
                q.push({a[i-1]+b[j-1],{i-1,j-1}});
                s.insert({i-1,j-1});
            }
        }

    }
    return ans;
}
