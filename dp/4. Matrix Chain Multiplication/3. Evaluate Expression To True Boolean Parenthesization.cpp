// https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1/
class Solution{
public:
unordered_map<string,int>m;
int mod=1003;
    int solve(string s,int i,int j, bool isTrue){
        string temp=to_string(i)+" "+to_string(j)+" "+(isTrue?'T':'F');
        if(m.find(temp)!=m.end()) return m[temp];
        if(i>j) return 0;
        if(i==j){
            if(isTrue) return m[temp]=s[i]=='T';
            else return m[temp]=s[i]=='F';
        }
        
        int ans=0;
        for(int k=i+1;k<=j-1;k+=2){
            
            int lt=solve(s,i,k-1,1);
            int lf=solve(s,i,k-1,0);
            int rt=solve(s,k+1,j,1);
            int rf=solve(s,k+1,j,0);
            if(s[k]=='&'){
                if(isTrue){
                    ans+=(lt*rt);
                }else{
                    ans+=(lt*rf)+(lf*rt)+(lf*rf);
                }
            }else if(s[k]=='|'){
                if(isTrue){
                    ans+=(lt*rt)+(lt*rf)+(lf*rt);
                }else ans+=(lf*rf);
            }else if(s[k]=='^'){
                if(isTrue){
                    ans+=(lf*rt)+(lt*rf);
                }else{
                    ans+=(lt*rt)+(lf*rf);
                }
            }
            
        }
        m[temp]=ans%mod;
        return ans%mod;
    }
    int countWays(int N, string S){
        // code here
        m.clear();
        return solve(S,0,N-1,1);
    }
};