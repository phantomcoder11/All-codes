class Solution {
public:
    bool isPalindrome(string s,int l,int h){
        while(l<=h){
            if(s[l++]!=s[h--]) return false;
        }
        return true;
    }
    void recursion(string &s,int idx,vector<vector<string>> &ans,vector<string>&v){
        if(idx==s.size()){
            
            ans.push_back(v);
            return;
        }
        for(int i=idx;i<s.size();i++){
         
            if(isPalindrome(s,idx,i)){
                v.push_back(s.substr(idx,i-idx+1));
                 recursion(s,i+1,ans,v);
            v.pop_back();
            }
            
           
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>v;
        recursion(s,0,ans,v);
        return ans;
    }
};