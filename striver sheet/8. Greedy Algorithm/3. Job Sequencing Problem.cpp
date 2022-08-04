class Solution 
{
    public:
    static bool comp(Job a,Job b){
        return a.profit>b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int x=0;
        for(int i=0;i<n;i++){
            x=max(x,arr[i].dead);
        }
        vector<int>val(x+1,-1);
        sort(arr,arr+n,comp);

        int sum=0,count=0;
        for(int i=0;i<n;i++){
          
            int j=arr[i].dead;
            
            while(val[j]!=-1 && j>0){
                    j--;
            }
            
            if(j==0) continue;
                val[j]=arr[i].id;
                sum+=arr[i].profit;
                count++;
            
        }
        // cout<<x<<endl;
        return {count,sum};
    } 
};