class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.00;
        long nm=n;
        if(n<0) nm=-nm;
        
        while(nm>0){
            if(nm%2==0){
                x=x*x;
                nm=nm/2;
            }else{
                ans=ans*x;
                nm=nm-1;
            }
        }
        if(n<0) ans=1.00/ans;
        return ans;
    }
};