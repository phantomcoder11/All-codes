class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";
        string ans="11";
        for(int i=3;i<=n;i++){
            ans+="#";
            int count=1;
            char prev=ans[0];
            string x="";
            for(int i=1;i<ans.size();i++){
                if(ans[i]!=ans[i-1]){
                   x+=to_string(count)+ans[i-1];
                   count=1; 
                }else count++;
            }
            ans=x;
        }
        return ans;
    }
};