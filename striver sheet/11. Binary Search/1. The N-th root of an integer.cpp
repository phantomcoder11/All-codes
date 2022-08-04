double power(double mid,int n){
    double ans=1.0;
    for(int i=0;i<n;i++){
        ans=mid*ans;
    }
    return ans;
}
double findNthRootOfM(int n, long long m) {
	// Write your code here.
    double low=1;
    double high=m;
    double esp=1e-8;
    
    while((high-low)>esp){
        double mid=(high+low)/2.0;
        if(power(mid,n)<(double)m){
            low=mid;
        }
        else{
            high=mid;
        }
    }
    return low;
}
