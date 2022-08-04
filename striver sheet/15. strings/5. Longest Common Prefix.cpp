// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        if(strs.size()==1) return strs[0];
        int i=0;
        sort(strs.begin(),strs.end());
        int n=strs.size();
        while(i<strs[0].length()){
            if(strs[0][i]!=strs[n-1][i]) break;
            i++;
        }
        return strs[0].substr(0,i);
    }
};