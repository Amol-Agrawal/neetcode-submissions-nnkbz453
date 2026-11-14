class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9,false));
        vector<vector<bool> >cols(9, vector<bool>(9,false));
        vector<vector<bool> >boxes(9, vector<bool>(9,false));

        for (int i= 0; i<9; i++){
            for(int j=0 ; j<9; j++){

                if(board[i][j]== '.') continue;

                int box = (i/3)*3 + j/3;
                int target = board[i][j] - '1' ;

                if(rows[i][target] || cols[j][target]|| boxes[box][target]){
                    return false;
                }
                rows[i][target] = true;
                cols[j][target] = true;
                boxes[box][target]= true;
            }
        }

        return true;
    }
};
