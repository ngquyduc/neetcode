class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // if any rows contain any duplicates
        for (int i = 0; i < 9; i++) {
            bool seen[9] = {};
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (seen[board[i][j] - '1']) {
                    return false;
                }
                seen[board[i][j] - '1'] = true;
            }
        }

        // if any columns contain any duplicates
        for (int i = 0; i < 9; i++) {
            bool seen[9] = {};
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') {
                    continue;
                }
                if (seen[board[j][i] - '1']) {
                    return false;
                }
                seen[board[j][i] - '1'] = true;
            }
        }
        
        // if any box contains any duplicates
        bool seen[9][9] = {};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (seen[i/3*3 + j/3][board[i][j] - '1']) {
                    return false;
                }
                seen[i/3*3 + j/3][board[i][j] - '1'] = true;
                
            }
        }
        
        return true;
    }
};
