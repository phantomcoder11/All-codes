class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        while(s[i]==' ') i++;
        bool sign =true;
        if(s[i]=='+' || s[i]=='-'){
            if(s[i]=='-') sign=false;
            i++;
        }
        int x=0;
        while(s[i]=='0') i++;
        while(i<s.length() && s[i]-'0'<=9 && s[i]-'0'>=0){
            if(x>INT_MAX/10 || (x==INT_MAX/10 && s[i]-'0'>7)){
                if(sign) return INT_MAX;
                else return INT_MIN;
            }
            x=x*10+(s[i]-'0');
            i++;
        }
        return (sign)?x:-x;
    }
};