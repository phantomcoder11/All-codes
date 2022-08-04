class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int l=0,r=0;
        int length=0;
        while(r<s.length()){
            if(m.find(s[r])!=m.end()){
                l=max(l,m[s[r]]+1);
            }
            length=max(r-l+1,length);
            m[s[r]]=r;
            r++;
        }
        return length;
    }
};