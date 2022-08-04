class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //Space O(n+m) Approach
//         unordered_map<string,int>m;
//         for(int i=0;i<matrix.size();i++){
//             for(int j=0;j<matrix[0].size();j++){
//                 if(matrix[i][j]==0){
                   
//                     m['r'+to_string(i)]=1;
//                     m['c'+to_string(j)]=1;
//                 }
//             }
//         }
        
//         for(int i=0;i<matrix.size();i++){
//             for(int j=0;j<matrix[0].size();j++){
                
//                 if(m['r'+to_string(i)]==1 ||  m['c'+to_string(j)]==1) matrix[i][j]=0;
//             }
//         }
        //Best Approach O(1) space approach
        int col0=1;
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0]==0) col0=0;
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        
        for(int i=matrix.size()-1;i>=0;i--){
            for(int j=matrix[0].size()-1;j>=1;j--){
                if(matrix[0][j]==0 || matrix[i][0]==0) matrix[i][j]=0;
                
            }
            if(col0==0){
                    matrix[i][0]=0;
                }
        }
    }
};