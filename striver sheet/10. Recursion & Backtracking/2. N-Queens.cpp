// 1st approach
// class Solution {
// public:
//     vector<vector<string>> solveNQueens(int n) {
//        vector<string>board(n);
//        vector<vector<string>>ans;
//        string s(n,'.');
//         for(int i=0;i<n;i++){
//             board[i]=s;
//         }
//         recursion(n,0,board,ans);
//         return ans;
//     }
//     void recursion(int n,int col,vector<string>&board,vector<vector<string>>&ans){
//         if(n==col){
//             ans.push_back(board);
//             return;
//         }
//         for(int row=0;row<n;row++){
//             if(isValid(row,col,board,n)){
//                 board[row][col]='Q';
//                 recursion(n,col+1,board,ans);
//                 board[row][col]='.';
//             }
//         }
//     }
    
//     bool isValid(int row,int col,vector<string>&board,int n){
//         int xrow=row,xcol=col;
        
//         while(row>=0 && col>=0){
//             if(board[row][col]=='Q') return false;
//             row--;
//             col--;
//         }
        
//         row=xrow;col=xcol;
        
//         while(col>=0){
//              if(board[row][col]=='Q') return false;
//              col--;
//         }
        
//         row=xrow;col=xcol;
        
//         while(col>=0 && row<n){
//              if(board[row][col]=='Q') return false;
//              col--;
//              row++;
//         }
//         return true;
//     }
// };

// 2nd approach

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
       vector<string>board(n);
       vector<vector<string>>ans;
       string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<int>lowerdiagonal(2*n-1,0);
        vector<int>upperdiagonal(2*n-1,0);
        vector<int>left(n,0);
        recursion(n,0,board,ans,lowerdiagonal,upperdiagonal,left);
        return ans;
    }
    void recursion(int n,int col,vector<string>&board,vector<vector<string>>&ans,vector<int>&lowerdiagonal,vector<int>&upperdiagonal,vector<int>&left){
        if(n==col){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(left[row]==0 && lowerdiagonal[col+row]==0 && upperdiagonal[n-1+col-row]==0){
                board[row][col]='Q';
                left[row]=1;
                lowerdiagonal[col+row]=1;
                upperdiagonal[n-1+col-row]=1;
                recursion(n,col+1,board,ans,lowerdiagonal,upperdiagonal,left);
                board[row][col]='.';
                left[row]=0;
                lowerdiagonal[col+row]=0;
                upperdiagonal[n-1+col-row]=0;
            }
        }
    }
    
   
};