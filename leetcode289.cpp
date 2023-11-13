/*
can either use an extra visited array or we can do it 
without extra array..(mark the elements that are supposed to 
change with something different)

-1 --> 0 and -2 --> 1

*/

class Solution {
public:

    int countOnes(vector<vector<int>>&board, int i, int j)
    {
        int count = 0;
        int rows[] = {-1, -1, -1, 0, +1, +1, +1, 0};
        int cols[] = {-1, 0, +1, +1, +1, 0, -1, -1};
        for(int i = 0; i < 8; i++){
            int nrow = i + rows[i];
            int ncol = i + cols[i];
            // check for 1 and coordinates validity
            if(nrow >= 0 && nrow < board.size() && ncol >= 0 && ncol < board[0].size() && board[nrow][ncol] == 1) count++; //got one 1
        }
        return count;
    }

    void gameOfLife(vector<vector<int>>& board) {

        vector<vector<int>>visited(board.size(), vector<int>(board[0].size(), 0));
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                // for eacth element check for the no. of ones
                // it is surrounded by..and don't go out of boundrary
                int totalOnes = countOnes(board, i, j);
                if(board[i][j] == 1){
                    if(totalOnes < 2) {
                        visited[i][j] = -1;
                    } 
                    else if(totalOnes > 3) {
                        visited[i][j] = -1;
                    }
                }
                else{
                    if(totalOnes == 3){
                        visited[i][j] = -2; //implies 1
                    }
                }
            }
        }

        // last traversal to make changes
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(visited[i][j] == -1){
                    board[i][j] = 0;
                }
                elseif(visited[i][j] == -2){
                    board[i][j] = 1;
                }
            }
        }
    return;
    }
};