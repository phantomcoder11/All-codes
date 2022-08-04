#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        if(s[0]==')' || s[0]=='}' || s[0]==']') return 0;
        int i=0;
        
        while(i<s.length()){
            
            
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            
            if(s[i]==')'){
                if(st.size() && st.top()=='(')  st.pop();
                else return false;
               
            } 
            
             if(s[i]=='}'){
                if(st.size() && st.top()=='{')  st.pop();
                else return false;
               
            } 
            
             if(s[i]==']'){
                if(st.size() && st.top()=='[')  st.pop();
                else return false;
               
            } 
            i++;
        }
      
        return st.empty();
    }
};