def chessboard_recolor(chess):
    m = len(chess)
    n = len(chess[0])
    min_changes = float('inf')

    for i in range(m - 7):
        for j in range(n - 7):
            changes_white = 0
            changes_black = 0

            for x in range(i, i + 8):
                for y in range(j, j + 8):
                    current_color = chess[x][y]

                    if (x + y) % 2 == (i + j) % 2:
                        if current_color != 'W':
                            changes_white += 1
                        else:
                            changes_black += 1
                    else:
                        if current_color != 'B':
                            changes_white += 1
                        else:
                            changes_black += 1
            min_changes = min(min_changes, changes_white, changes_black)
    return min_changes

m, n = map(int, input().split())
chess = [input()[:n] for _ in range(m)]
min_changes = chessboard_recolor(chess)
print(min_changes)