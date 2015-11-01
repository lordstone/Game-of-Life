class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> arr;
        if(board.size() == 0) return;
        if(board.size() == 1 && board[0].size() == 0) return;
        if(board[0].size() == 1 && board.size() == 1) {
            board[0][0] = 0;
            return;
        }
        
        for(int i = 0; i < board.size(); i ++){
            vector<int> tmp(board[0].size(), 0);
            arr.push_back(tmp);
        }//end for i
        
        for(int i = 0; i < board.size(); i ++){
            for(int j = 0; j < board[0].size(); j ++){
                int foo = 0;
                
                foo += (i > 0)? board[i - 1][j]:0;
                foo += (i > 0 && j > 0)? board[i - 1][j - 1]:0;
                foo += (i > 0 && j < board[0].size() - 1)? board[i - 1][j + 1]:0;
                
                foo += (i < board.size() - 1)? board[i + 1][j]:0;
                foo += ((i < board.size() - 1) && j > 0)? board[i + 1][j - 1]:0;
                foo += ((i < board.size() - 1) && j < board[0].size() - 1)? board[i + 1][j + 1]:0;
                
                foo += (j > 0)? board[i][j - 1]:0;
                foo += (j < board[0].size() - 1)? board[i][j + 1]:0;
                
                //arr[i][j] = foo;
                
                if(board[i][j] == 1){
                    if(foo < 2) arr[i][j] = 0;
                    else if(foo == 2 || foo == 3) arr[i][j] = 1;
                    else if(foo > 3) arr[i][j] = 0;
                }else{
                    if(foo == 3) arr[i][j] = 1;
                    else arr[i][j] = 0;
                }//end if
                
            }//end for j
        }//end for i
        
        board = arr;//give the updated table to the original one
    }//end main
};
