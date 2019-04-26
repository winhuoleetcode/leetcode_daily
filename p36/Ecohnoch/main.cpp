#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[10] = {0}, cols[10] = {0}, inner[10] = {0};

        for(int i = 0; i < 9; ++i){
            memset(rows, 0, sizeof(rows));
            memset(cols, 0, sizeof(cols));
            memset(inner, 0, sizeof(inner));

            for(int j = 0; j < 9; ++j){
                if(board[i][j] != '.'){
                    int ind = board[i][j] - '0';
                    rows[ind] += 1;
                    if(rows[ind] != 1){
                        cout<<"rows"<<endl;
                        return false;
                    }
                }
                if(board[j][i] != '.'){
                    int ind = board[j][i] - '0';
                    cols[ind] += 1;
                    if(cols[ind] != 1){
                        cout<<"cols"<<endl;
                        return false;
                    }
                }
                if(board[3*(int)(i/3) + (int)(j/3)][3*(i%3) + j%3] != '.'){
                    int ind = board[3*(int)(i/3) + (int)(j/3)][3*(i%3) + j%3] - '0';
//                    cout<<i<<" "<<j<<" "<<3*(int)(i/3) + (int)(j/3)<<" "<< 3*i + j%3<<endl;
                    inner[ind] += 1;
                    if(inner[ind] != 1){
                        cout<<"inner "<< i<<endl;
                        return false;
                    }
                }
            }
        }
        return true;

    }
};

int main(){
    Solution s;
    vector<vector<char>>  test = {
            {'5','3','.','.','7','.','.','.','.'},
            {'2','.','3','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
          };
    cout<<s.isValidSudoku(test)<<endl;

    return 0;
}
