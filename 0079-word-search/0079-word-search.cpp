class Solution {
public:
bool func(int row,int col,int index,vector<vector<char>>&board,string &word){
    if(index==word.length()) return true;
    if(row<0 || row >= board.size() || col < 0 || col>=board[0].size()) return false;
    if(board[row][col] != word[index]) return false;
    char temp = board[row][col];
    board[row][col] = '#';

    bool found =
        func(row - 1, col, index + 1, board, word) ||
        func(row + 1, col, index + 1, board, word) ||
        func(row, col - 1, index + 1, board, word) ||
        func(row, col + 1, index + 1, board, word);

    board[row][col] = temp;

return found;   
}
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (func(i, j, 0, board, word))
                    return true;
            }
        }
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna