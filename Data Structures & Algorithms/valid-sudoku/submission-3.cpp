class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> boxes(9);
        vector<unordered_set<int>> columns(9);
        vector<unordered_set<int>> rows(9);

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (rows[i].find(board[i][j]) != rows[i].end()) {
                    return false;
                }
                rows[i].insert(board[i][j]);

                if (columns[j].find(board[i][j]) != columns[j].end()) {
                    return false;
                }
                columns[j].insert(board[i][j]);

                int box = (i / 3) * 3 + j / 3; 
                if (boxes[box].find(board[i][j]) != boxes[box].end()) {
                    return false;
                }
                boxes[box].insert(board[i][j]); 
            }
        }
        return true;
    }
};
