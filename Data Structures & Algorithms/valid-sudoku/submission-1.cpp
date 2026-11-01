class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // if any rows contain any duplicates
        for (int i = 0; i < 9; i++) {
            unordered_set<int> row_check;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (row_check.contains(board[i][j])) {
                    return false;
                }
                row_check.insert(board[i][j]);
            }
        }

        // if any columns contain any duplicates
        for (int i = 0; i < 9; i++) {
            unordered_set<int> column_check;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') {
                    continue;
                }
                if (column_check.contains(board[j][i])) {
                    return false;
                }
                column_check.insert(board[j][i]);
                
            }
        }
        
        // if any box contains any duplicates
        vector<unordered_set<int>> boxes_check(9);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') {
                    continue;
                }
                if (boxes_check[i/3*3 + j/3].contains(board[j][i])) {
                    return false;
                }
                boxes_check[i/3*3 + j/3].insert(board[j][i]);
                
            }
        }
        
        return true;
    }
};
