class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=i;j<matrix.size();j++){
                if(i!=j){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
        // for(int i=0;i<matrix.size();i++){
        //     for(int j=0;j<matrix.size();j++){
        //         cout<<matrix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size()/2;j++){
                // cout<<matrix[i][j]<<" "<<matrix[i][matrix.size()-j-1]<<endl;
                swap(matrix[i][j],matrix[i][matrix.size()-j-1]);
            }
        }
        // cout<<endl;
        // for(int i=0;i<matrix.size();i++){
        //     for(int j=0;j<matrix.size();j++){
        //         cout<<matrix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
    }
};