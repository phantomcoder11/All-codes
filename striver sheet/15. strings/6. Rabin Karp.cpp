// https://leetcode.com/problems/repeated-string-match/
// https://practice.geeksforgeeks.org/problems/0cba668df04d657fde4d1bd28b626a01e61097f1/1


//Brute Force
class Solution {
public:
    bool checksubstring(string a,string b){
        for(int i=0;i<a.length();i++){
            if(a[i]==b[0]){
                int k=i+1;
                int j=1;
                while(j<b.length() && k<a.length()){
                    if(a[k]==b[j]){
                        k++;
                        j++;
                    }else break;
                }
                if(j==b.length()) return true;
            }
        }
        return false;   
    }
    int repeatedStringMatch(string a, string b) {
        int count=1;
        string temp=a;
        while(a.length()<b.length()){
            a=a+temp;
            count++;
        }
        if(checksubstring(a,b)){
            return count;
        }
        if(checksubstring(a+temp,b)) return count+1;
        return -1;
        
    }
};

