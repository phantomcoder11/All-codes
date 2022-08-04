//  Roman to Integer
// https://leetcode.com/problems/roman-to-integer/
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        int ans=0;
        for(int i=0;i<s.length();i++){
          if(i!=s.length()-1 && m[s[i]]<m[s[i+1]]){
              ans+=m[s[i+1]]-m[s[i]];
              i++;
          }else{
              ans+=m[s[i]];
          }
        }
        return ans;
    }
};

// Integer to Roman
// https://leetcode.com/problems/integer-to-roman/

class Solution {
public:
    
    string intToRoman(int num) {
       int integer[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
       string roman[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        string ans="";
        for(int i=0;i<13;i++){
            int value = integer[i];
            while(num>=value){
                ans+=roman[i];
                num-=value;
            }
        }
        return ans;
    }
};