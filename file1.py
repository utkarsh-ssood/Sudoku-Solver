def print_puzzle(board):
    SIZE = 3
    for i in range(len(board)):
        print("\t\t\t", end="")
        for j in range(len(board[0])):
            if j == SIZE * SIZE - 1:
                print(board[i][j], end="")
                continue
            print(board[i][j], end=" | ")
        print()
        if i != SIZE * SIZE - 1:
            print("\t\t\t---|---|---|---|---|---|---|---|---")
    print("\n")


def input_puzzle():
    SIZE = 3
    board = [['*' for _ in range(SIZE * SIZE)] for _ in range(SIZE * SIZE)]
    k = 1
    print("Location of positions with respect to each individual 3*3 block:\n")
    for i in range(SIZE):
        print("\t\t\t", end="")
        for j in range(SIZE):
            if j == SIZE - 1:
                print(k, end="")
                k += 1
                continue
            print(k, end=" | ")
            k += 1
        print()
        if i != SIZE - 1:
            print("\t\t\t--| --| --")
    print()

    k = 1
    print("Location of each block:\n")
    for i in range(SIZE):
        print("\t\t\t", end="")
        for j in range(SIZE):
            if j == SIZE - 1:
                print(f"Block {k}", end="")
                k += 1
                continue
            print(f"Block {k}", end=" | ")
            k += 1
        print()
        if i != SIZE - 1:
            print("\t\t\t------- | ------- | -------")
    print()

    k = 0
    temp = 0
    print("Enter -1 for empty spaces.")
    m = 1
    for i in range(0, SIZE * SIZE, SIZE):
        for j in range(0, SIZE * SIZE, SIZE):
            k = 1
            for row in range(i, i + SIZE):
                for col in range(j, j + SIZE):
                    temp = int(input(f"Enter number at Block {m} and Position {k} : "))
                    if (0 < temp <= 9) or (temp == -1):
                        pass
                    else:
                        print("Enter a valid number and try again.\n\n")
                        exit(0)
                    if temp != -1:
                        board[row][col] = str(temp)
                    k += 1
            m += 1

    print("The entered board is:")
    print_puzzle(board)
    return board


def is_valid(board, row, col, c):
    SIZE = 3
    for i in range(len(board)):
        if board[i][col] == c:
            return False
        if board[row][i] == c:
            return False
        if board[3 * (row // 3) + i // 3][3 * (col // 3) + i % 3] == c:
            return False
    return True


def fun(board):
    SIZE = 3
    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] == '*':
                for c in '123456789':
                    if is_valid(board, i, j, c):
                        board[i][j] = c
                        if fun(board):
                            return True
                        else:
                            board[i][j] = '*'
                return False
    return True


def solve_sudoku(board):
    print("The output board is:")
    if fun(board):
        print_puzzle(board)
    else:
        print("\nEnter a valid problem.\n\n")


if __name__ == "__main__":
    while True:
        board = input_puzzle()
        solve_sudoku(board)
        c = input("Do you want to exit? (y/n) : ")
        if c == 'n':
            print("Initiating new program launch...")
        else:
            break
