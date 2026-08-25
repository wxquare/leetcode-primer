class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[10][10],cols[10][10],subboxes[3][3][10];
        memset(rows,0,sizeof(rows));
        memset(cols,0,sizeof(cols));
        memset(subboxes,0,sizeof(subboxes));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.') continue;
                int d = board[i][j] - '0';
                if(rows[i][d] || cols[j][d]) return false;
                if(subboxes[i/3][j/3][d]) return false;
                rows[i][d] = true;
                cols[j][d] = true;
                subboxes[i/3][j/3][d] = true;
            }
        }
        return true;
    }
};