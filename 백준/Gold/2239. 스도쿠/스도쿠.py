import sys

def sudoku(board):
    def is_corrent(num, row, col):
        num_mask = 1 << num
        return (row_mask[row] & num_mask) == 0 and (col_mask[col] & num_mask) == 0 and (box_mask[row // 3][col // 3] & num_mask) == 0

    def place_number(num, row, col):
        num_mask = 1 << num
        row_mask[row] |= num_mask
        col_mask[col] |= num_mask
        box_mask[row // 3][col // 3] |= num_mask
        board[row][col] = num

    def remove_number(num, row, col):
        num_mask = 1 << num
        row_mask[row] &= ~num_mask
        col_mask[col] &= ~num_mask
        box_mask[row // 3][col // 3] &= ~num_mask
        board[row][col] = 0

    empty_cells = [(row, col) for row in range(9) for col in range(9) if board[row][col] == 0]

    def backtrack(index):
        if index == len(empty_cells):
            return True

        row, col = empty_cells[index]

        for num in range(1, 10):
            if is_corrent(num, row, col):
                place_number(num, row, col)
                if backtrack(index + 1):
                    return True
                remove_number(num, row, col)

        return False

    row_mask = [0] * 9
    col_mask = [0] * 9
    box_mask = [[0] * 3 for _ in range(3)]

    for row in range(9):
        for col in range(9):
            if board[row][col] != 0:
                place_number(board[row][col], row, col)

    if backtrack(0):
        return board
    else:
        return None

if __name__ == "__main__":
    sudoku_arr = [[0 for _ in range(9)] for _ in range(9)]
    for i in range(9):
        sudoku_arr[i] = list(map(int, sys.stdin.readline().rstrip()))

    ans = sudoku(sudoku_arr)
    for i in ans:
        print(''.join(map(str, i)))