/* For each start point as a character, we have four directions, but it can be reduced to 3, because we won't go back to where we come from. Then, we continue going three directions for
each character ==> we can visualize they are a 3-ary tree ==> for the time complexity in worst case are equal the total node in this tree. Besides, we will stop the searching when we
find the satisfied word <=> the depth of this tree <=> the length of the word ==> the total node 3^L with L is the length of the word. However, the worst case for the whole matrix that
happens when we loop all of the characters in the matrix ==> the time complexity is m*n*3^L, m and n are number of rows and column of the matrix.

The space complexity is equal the consumption memory used by recursion function. They are saved into the stack, so the maximum of the stack <=> the length of the word
==> space complexity is O(L) */


class Solution {
public:
    bool check = false;
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        int len = word.length();
        
        // loop every character of matrix => find the word based on this character ==> check with the word
        string checkWord = "";
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == word[0]){
                    if(findPath(i,j, board, word)) return true;
                    
                }
            }
        }
        return check;
    }

    bool findPath(int r, int c, vector<vector<char>>&board, string word){
        if(r < 0 || r == board.size() || c < 0 || c == board[0].size() || board[r][c] != word[0]) return false;
        
        char temp = board[r][c];
        board[r][c] = '*';
        word = word.substr(1);
        if(word.length() == 0) return true;
        
        bool ret = findPath(r-1, c, board, word) || findPath(r+1, c, board, word) || findPath(r, c-1, board, word) || findPath(r, c+1, board, word);
        board[r][c] = temp;
        return ret;
    }
};
