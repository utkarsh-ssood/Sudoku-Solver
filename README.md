# Sudoku Solver using Backtracking and Input Validation Algorithm
## Introduction
This project features a Sudoku-Solver program implemented in C++ that uses the Backtracking Algorithm to find solutions for Sudoku puzzles. It also incorporates an Input Validation Algorithm to ensure that the user provides valid Sudoku boards.

## Features
* Solve Sudoku Puzzles: Utilizes the backtracking algorithm to find solutions for given Sudoku puzzles.
* Input Validation: Validates user input to ensure that the entered Sudoku board is correct before attempting to solve it.
* Interactive Interface: Provides a user-friendly interface for input and displays the solution.

## Rules of Sudoku

The rules of Sudoku are as follows:
* The Sudoku board is a 9x9 grid, divided into nine 3x3 sub-grid (blocks).
* Each cell in the Sudoku board should contain a digit from 1 to 9.
* Each of the digits 1-9 must occur exactly once in each row.
* Each of the digits 1-9 must occur exactly once in each column.
* Each of the digits 1-9 must occur exactly once in each of the 9 3x3 blocks of the 9*9 grid.

## How to Use
* Clone the repository or download the source code.
* Compile the C++ code using a C++ compiler.
* Run the compiled executable file to start the Sudoku Solver program.
* Input the Sudoku board as mentioned.
* The program will validate the input for correctness.
* If the input is valid, the initial Sudoku puzzle will be displayed.
* Press 'Enter' to start the solver using the backtracking algorithm.
* The program will display the solved Sudoku board if a solution exists or notify you if the puzzle is unsolvable.

## Input Validation Algorithm
The Input Validation Algorithm ensures that the Sudoku board meets the following criteria:

* 9x9 Grid: The board should have exactly 9 rows and 9 columns.
* Valid Digits: Each cell should contain a single digit from 1 to 9 or '*' for empty cells.
* Digit Range: Digits should be placed in the correct range (1 to 9 for valid entries), and '*' for empty cells.
* No Repeats: The board should not contain any repeated digits in any row, column, or 3x3 subgrid.

## Backtracking Algorithm
The backtracking algorithm follows these steps to find the Sudoku puzzle solution:
* Place Digits: Start by placing digits (1 to 9) in empty cells, one at a time.
* Check Validity: After placing a digit, verify that the configuration is valid by checking the Sudoku rules in the corresponding row, column, and 3x3 subgrid.
* Backtrack: If the configuration is valid, proceed to fill the next empty cell. If no valid digit can be placed, backtrack to the previous cell and try a different digit.
* Repeat: Continue this process until a valid solution is found or all possible configurations are explored.

## Pseudocode
```
Procedure solveSudoku(board)
    If the board is completely filled
        Return true (Puzzle is solved)
    
    Find an empty cell (cell with 0) in the board
    For digit from 1 to 9
        If digit is safe to place in the cell
            Place the digit in the cell
            If solveSudoku(board) returns true
                Return true (Puzzle is solved)
            Remove the digit from the cell (backtrack)
    
    Return false (Puzzle is unsolvable)

Procedure isValid(board, row, col, digit)
    Check if the digit is not in the current row
    Check if the digit is not in the current column
    Check if the digit is not in the current 3x3 subgrid
    If all checks pass
        Return true (Digit placement is valid)
    Else
        Return false (Digit placement is invalid)

Procedure main()
    Input the Sudoku board
    If the board is valid (using isValid procedure)
        If solveSudoku(board) returns true
            Display the solved Sudoku board
        Else
            Display "No solution exists for this puzzle."
    Else
        Display "Invalid Sudoku board. Please enter a valid board."
```

To initiate the program, call the main() function :
```
main()
```
## Example

### Input:
![image](https://github.com/utkarsh-ssood/Sudoku-Solver/assets/122226447/6d5d7228-9cce-4e50-81c3-76d7875e0d08)

### Output:
![image](https://github.com/utkarsh-ssood/Sudoku-Solver/assets/122226447/e2c64acc-0c1a-4a23-b38d-901ecfebff2b)


## Sample Visualization
![image](https://github.com/utkarsh-ssood/Sudoku-Solver/assets/122226447/00b078ba-e7b2-4510-bf70-532f79bd6c33)
<br>Similarly we can fill all the remaining blocks.
If a recursive call returns true, we can assume that we found one possible way of filling and we simply do an early return.

## Conclusion
With this Sudoku Solver program, you can efficiently solve Sudoku puzzles using the Backtracking Algorithm while ensuring valid input through the Input Validation algorithm.
