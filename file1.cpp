#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 3;

void printPuzzle(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        cout << "\t\t\t";
        for (int j = 0; j < board[0].size(); j++)
        {
            if (j == SIZE * SIZE - 1)
            {
                cout << board[i][j];
                continue;
            }
            cout << board[i][j] << " | ";
        }
        cout << "\n";
        if (i != SIZE * SIZE - 1)
        {
            cout << "\t\t   \t\b---|---|---|---|---|---|---|---|--- \n";
        }
    }
    cout << endl
         << endl;
}

vector<vector<char>> inputPuzzle()
{
    vector<vector<char>> board(SIZE * SIZE, vector<char>(SIZE * SIZE, '*'));
    int k = 1;
    cout << "Location of positions with respect to each individual 3*3 block :\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << "\t\t\t";
        for (int j = 0; j < SIZE; j++)
        {
            if (j == SIZE - 1)
            {
                cout << k;
                k++;
                continue;
            }
            cout << k << " | ";
            k++;
        }
        cout << "\n";
        if (i != SIZE - 1)
            cout << "\t\t\t--| --| -- \n";
    }
    cout << "\n";

    k = 1;
    cout << "Location of each block: \n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << "\t\t\t";
        for (int j = 0; j < SIZE; j++)
        {
            if (j == SIZE - 1)
            {
                cout << "Block " << k;
                k++;
                continue;
            }
            cout << "Block " << k << " | ";
            k++;
        }
        cout << "\n";
        if (i != SIZE - 1)
            cout << "\t\t\t------- | ------- | -------  \n";
    }
    cout << "\n";

    k = 0;
    int temp = 0;
    cout << "Enter " << -1 << " for empty spaces.\n";
    int m = 1;
    for (int i = 0; i < SIZE * SIZE; i += SIZE)
    {
        for (int j = 0; j < SIZE * SIZE; j += SIZE)
        {
            int k = 1;

            for (int row = i; row < i + SIZE; row++)
            {
                for (int col = j; col < j + SIZE; col++)
                {

                    cout << "Enter number at Block " << m
                         << " and Position " << k++ << " : ";
                    cin >> temp;
                    if((temp>0&&temp<=9)||(temp==-1))
                    {

                    }
                    else
                    {
                        cout<<"Enter a valid number and try again.\n\n";
                        exit(0);
                    }
                    
                    if (temp != -1)
                        board[row][col] = temp + '0';
                }
            }
            m++;
        }
    }

    cout << "The entered board is: \n";
    printPuzzle(board);
    cout << endl
         << endl;
    return board;
}

bool isValid(vector<vector<char>> &board, int row, int col, char c)
{
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i][col] == c)
        {
            return false;
        }
        if (board[row][i] == c)
        {
            return false;
        }
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
        {
            return false;
        }
    }
    return true;
}

bool fun(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == '*')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    if (isValid(board, i, j, c))
                    {
                        board[i][j] = c;
                        if (fun(board) == true)
                        {
                            return true;
                        }
                        else
                        {
                            board[i][j] = '*';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{

    cout << "The output board is: \n";
    if (fun(board))
        printPuzzle(board);
    else
    {
        cout << "\nEnter a valid problem.\n\n";
    }
}

int main()
{
    char c = 'n';
    while (true)
    {
        vector<vector<char>> board = inputPuzzle();
        solveSudoku(board);
        cout << "Do you want to exit?(y/n) : ";
        cin >> c;
        if(c=='n')
        {
            cout<<"Initiating new program launch...\n";
        }
        else{
            break;
        }
    }
    return 0;
}