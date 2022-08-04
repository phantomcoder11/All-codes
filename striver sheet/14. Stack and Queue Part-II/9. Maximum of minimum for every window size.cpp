

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector<int> range(int arr[],int n){
        stack<pair<int,int>>s1;
        vector<int>nsl;
        for(int i=0;i<n;i++){
            if(s1.empty()){
                nsl.push_back(-1);
            }else if(s1.size() && s1.top().first<arr[i]){
                nsl.push_back(s1.top().second);
            }else{
                while(s1.size() && s1.top().first>=arr[i]){
                    s1.pop();
                }
                if(s1.empty()) nsl.push_back(-1);
                else nsl.push_back(s1.top().second);
            }
            s1.push({arr[i],i});
        }
       
        
        stack<pair<int,int>>s2;
        vector<int>nsr;
        for(int i=n-1;i>=0;i--){
            if(s2.empty()) nsr.push_back(n);
            else if(s2.size() && s2.top().first<arr[i]) nsr.push_back(s2.top().second);
            else{
                while(s2.size() && s2.top().first>=arr[i]) s2.pop();
                if(s2.empty()) nsr.push_back(n);
                else nsr.push_back(s2.top().second);
            }
            s2.push({arr[i],i});
        }
       
        vector<int> v(n);
        for(int i=0;i<n;i++){
            // cout<<nsr[i]<<" "<<nsl[i]<<endl;
            v[i]=nsr[n-i-1]-nsl[i]-1;
        }
        return v;
    }
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        
        vector<int>x=range(arr,n);
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
           ans[x[i]-1]=max(ans[x[i]-1],arr[i]);
        }
        int last=ans[n-1];
        
        for(int i=n-2;i>=0;i--){
            ans[i]=max(ans[i],ans[i+1]);
            // if(ans[i]<ans[i+1]) ans[i]=ans[i+1];
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends