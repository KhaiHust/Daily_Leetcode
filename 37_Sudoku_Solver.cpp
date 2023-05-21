#include <bits/stdc++.h>
// using namespace std;
// void Try(vector<vector<char>> &board, int row, int col){
//     if(col == 9){
//         if(row == 8) return;
//         else Try(board, row + 1, 0);
//     }
//     else if(board[row][col] == '.'){
//         for(char ch = '1'; ch <= '9'; ch++){
//              if(checkValid(board,ch, row, col)){
//                 board[row][col] = ch;
//                 Try(board, row, col + 1);
//                 board[row][col] = '.';
//              }
//         }

//     }
//     else{
//         Try(board, row, col + 1);
//     }

// }
// void solveSudoku(vector<vector<char>> &board)
// {
//     Try(board, 0, 0);
// }
// bool checkValid(vector<vector<char>> &board, char ch, int row, int col)
// {
//     for (int i = 0; i < 9; i++)
//     {
//         if (ch == board[row][i])
//             return false;
//     }

//     for (int i = 0; i < 9; i++)
//     {
//         if (ch == board[i][col])
//             return false;
//     }
//     for (int i = 3 * (row / 3); i < 3 * (row / 3) + 3; i++)
//     {
//         for (int j = 3 * (col / 3); j < 3 * (col / 3) + 3; j++)
//         {
//             if (ch = board[i][j])
//                 return false;
//         }
//     }
//     return true;
// }
// int main()
// {
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     vector<vector<char>> board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]];

// }
// #include <iostream>
// #include <vector>

using namespace std;

bool checkValid(vector<vector<char>> &board, char ch, int row, int col)
{
    for (int i = 0; i < 9; i++)
    {
        if (ch == board[row][i])
            return false;
    }

    for (int i = 0; i < 9; i++)
    {
        if (ch == board[i][col])
            return false;
    }

    int r = row / 3 * 3;
    int c = col / 3 * 3;
    for (int i = r; i < r + 3; i++)
    {
        for (int j = c; j < c + 3; j++)
        {
            if (ch == board[i][j])
                return false;
        }
    }

    return true;
}

bool Try(vector<vector<char>> &board, int &row, int &col)
{
    if (col == 9)
    {
        col = 0;
        row++;
        if (row == 9)
            return true;
    }
    if (board[row][col] == '.')
    {
        for (char ch = '1'; ch <= '9'; ch++)
        {
            if (checkValid(board, ch, row, col))
            {
                board[row][col] = ch;
                if (Try(board, row, col))
                    return true;
                board[row][col] = '.';
            }
        }
        return false;
    }
    else
    {
        col++;
        if (Try(board, row, col))
            return true;
    }
    return false;
}

void solveSudoku(vector<vector<char>> &board)
{
    int row = 0, col = 0;
    Try(board, row, col);
}

void printBoard(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
            if (j % 3 == 2)
                cout << "| ";
        }
        cout << endl;
        if (i % 3 == 2)
            cout << "---------------------" << endl;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    cout << "Original board:" << endl;
    printBoard(board);

    solveSudoku(board);

    cout << endl
         << "Solved board:" << endl;
    printBoard(board);

    return 0;
}
