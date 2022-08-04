class Solution {
public:
//The first integer of each row is greater than the last integer of the previous row.
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int low=0,high=matrix.size()*matrix[0].size()-1;
        int m=matrix[0].size();
        while(low<=high){
            int mid = (low+high)/2;
            if(matrix[mid/m][mid%m]==target) return true;
            else if(matrix[mid/m][mid%m]>target){
                high=mid-1;
            } 
            else low=mid+1;
        }
        return false;
    }
    //If not like in gfg version 
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0,j=matrix[0].size()-1;
        while(i<matrix.size() && j>=0){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target){
                j--;
            } 
            else i++;
        }
        return false;
    }
};