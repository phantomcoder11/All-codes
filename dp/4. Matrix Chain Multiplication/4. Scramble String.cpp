// https://www.interviewbit.com/problems/scramble-string/
//Recursive approach
bool solve(string a,string b){
    if(a==b) return true;
    if(a.length()<=1) return false;
    bool flag=false;
    int n=a.length();
    for(int i=1;i<=n-1;i++){
        bool swap=solve(a.substr(0,i),b.substr(n-i,i)) &&
                  solve(a.substr(i,n-i),b.substr(0,n-i));
        bool noswap=solve(a.substr(0,i),b.substr(0,i)) &&
                  solve(a.substr(i,n-i),b.substr(i,n-i));
        if(swap || noswap){
            flag=true;
            break;
        }
    }
    return flag;
}
int Solution::isScramble(const string A, const string B) {
    if(A.length()!=B.length()) return 0;
    if(A.length()==0) return 1;
    return solve(A,B);
}


// Memoized Approach

unordered_map<string,int>m;
bool solve(string a,string b){
    string key=a+" "+b;
    if(m.find(key)!=m.end()) return m[key];
    if(a==b) return m[key]=true;
    if(a.length()<=1) return false;
    bool flag=false;
    int n=a.length();
    for(int i=1;i<=n-1;i++){
        bool swap=solve(a.substr(0,i),b.substr(n-i,i)) &&
                  solve(a.substr(i,n-i),b.substr(0,n-i));
        bool noswap=solve(a.substr(0,i),b.substr(0,i)) &&
                  solve(a.substr(i,n-i),b.substr(i,n-i));
        if(swap || noswap){
            flag=true;
            break;
        }
    }
    return m[key]=flag;
}
int Solution::isScramble(const string A, const string B) {
    if(A.length()!=B.length()) return 0;
    if(A.length()==0) return 1;
    m.clear();
    return solve(A,B);
}
