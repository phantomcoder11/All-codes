class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool comp(Item a,Item b){
        double x=(double)a.value/a.weight;
        double y=(double)b.value/b.weight;
        return x>y ;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,comp);
        double val=0;
  
        for(int i=0;i<n;i++){
         
            if(arr[i].weight<=W){
                
                val+=arr[i].value;
                W=W-arr[i].weight;
            }else{
                double x=(double)arr[i].value/arr[i].weight;
                val+=W*x;
                break;
            }
        }
        return val;
    }
        
};