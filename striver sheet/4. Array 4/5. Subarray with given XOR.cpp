int Solution::solve(vector<int> &A, int B) {
    int x=0;
    int ans=0;
    unordered_map<int,int>m;
    int xr=0; //This will be our prefix xor
    int y;
    for(int i=0;i<A.size();i++){
        xr=xr^A[i];
        if(xr==B) ans++;
        y=B^xr;
        if(m.find(y)!=m.end()) ans+=m[y];
        m[xr]++;
    }
    return ans;
}
