N, M = [int(x) for x in input().split()]

lines = []
col_sum = [0] * M
row_sum = [0] * N
hashes = 0

for _ in range(N):
    lines.append(input())

for i, v in enumerate(lines):
    for j, w in enumerate(v):
        if w == '#':
            hashes += 1
            col_sum[j] += 1
            row_sum[i] += 1


max_row = max(row_sum)
max_col = max(col_sum)
print(max_row + max_col - 2 + 2 * (hashes - max_row - max_col + 1))
