class Solution {
public:
    int totalNQueens(int n) {
        //if the constraints are too small => (might imply) TC -> exponential => Backtracking
        int count = 0;
        vector<string>board(n,string(n,'.'));
        backtrack(count,board,0,n);
        return count;
    }
    void backtrack(int &count,vector<string> &board,int i,int n){
        if(i==n){
            count++;
            return;
        }
        for(int j=0;j<n;j++){
            if(check(board,i,j,n)){
                board[i][j]='Q';
                backtrack(count,board,i+1,n);
                board[i][j]='.';
            }
        }
        return ;
    }
    bool check(vector<string> &board,int row,int col,int n){
        //Column Checking
        for(int j=0;j<n;j++){
            if(board[j][col]=='Q') return false;
        }
        //Upper Left Diagonal
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q') return false;
        }
        //Upper Right Diagonal
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q') return false;
        }

        return true;
    }
};