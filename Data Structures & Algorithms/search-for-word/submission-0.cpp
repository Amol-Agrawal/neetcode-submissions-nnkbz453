class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int r = 0 ; r< board.size(); r++){
            for(int c = 0 ; c< board[0].size(); c++){
                if( f( board, word, r, c, 0)){
                    return true;
                }
            }
        }

        return false;



    }

    bool f(vector<vector<char>>& board, string word, int r , int c ,int i ){

        if( i == word.size()) return true;

        if( r < 0 || c < 0 || r>= board.size() || c>= board[0].size()
            || board[r][c] == '#' || board[r][c]!= word[i]){
                return false ;
            }

        board[r][c] = '#';
        
        bool res = ( f(board, word, r+1, c, i+1) ||
            f(board, word, r, c+1, i+1) ||
            f(board, word, r-1, c, i+1) ||
            f(board, word, r, c-1, i+1) );

        board[r][c] = word[i];

        return res;
    }


};
