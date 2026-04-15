def solve_n_queens(n):
    def backtrack(row, columns, diagonals1, diagonals2):
        if row == n:
            return 1
        count = 0
        available_positions = ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2))
        while available_positions:
            position = available_positions & -available_positions
            available_positions -= position
            count += backtrack(row + 1, columns | position, (diagonals1 | position) << 1, (diagonals2 | position) >> 1)
        return count

    return backtrack(0, 0, 0, 0)

n = int(input())
print(solve_n_queens(n))
