class Solution {
public:
bool issafe(int row,int col,vector<vector<char>> board,int n){
    int mrow=row;
    int ncol=col;
    while(row>=0 && col>=0){
        if(board[row][col]=='Q') return false;
        row--;
        col--;
    }

    col=ncol;
    row=mrow;
    while(col>=0){
        if(board[row][col]=='Q') return false;
        col--;
    }
    row=mrow;
    col=ncol;
    while(row<n && col>=0){
        if(board[row][col]=='Q') return false;
        row++;
        col--;
    }
    return true;
}
void solve(int col, vector<vector<char>> &board, vector<vector<string>> &ans, int n)
{
    if (col == n)
    {
        vector<string> temp;
        for (int i = 0; i < n; i++)
        {
            // Convert row vector to string
            string row(board[i].begin(), board[i].end());
            temp.push_back(row);
        }
        ans.push_back(temp);
        return;
    }

    for(int i=0;i<n;i++){
        if(issafe(i,col,board,n)){
            board[i][col]='Q';
            solve(col+1,board,ans,n);
            board[i][col]='.';
        }
    }
}

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        // Create empty board of size n x n
        vector<vector<char>> board(n, vector<char>(n, '.'));

        // Start backtracking from column 0
        solve(0, board, ans, n);
        return ans;
    }
};