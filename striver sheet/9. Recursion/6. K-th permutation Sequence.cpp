class Solution {
public:

    string getPermutation(int n, int k) {
        vector<int>v(n);
        for(int i=0;i<n;i++){
            v[i]=i+1;
        }
        string s="";
      
       int fact=1;        
        for(int i=1;i<n;i++){
            fact=fact*i;
        }
        int size=n;
        k--;
        while(1){
            s+=to_string(v[k/ fact]);
            
            v.erase(v.begin()+k/ fact);
            if(v.size()==0) break;
            k=k% fact;
            fact=fact/v.size();   
        }
        return s;
    }
};