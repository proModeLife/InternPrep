import math

def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def fill_grid(grid, n, m, row, col, used):
    if row == n:
        return True  # filled all cells, found a solution

    next_row = row if col < m - 1 else row + 1
    next_col = col + 1 if col < m - 1 else 0

    for num in range(n * m):
        if used[num]:
            continue  # number already used in row or column
         
        if col > 0 and is_prime(abs(num +1- grid[row][col - 1])):
            continue  # adjacent cells differ by 1
        if col > m and is_prime(abs(num+1 - grid[row][col+1])):
            continue  # adjacent cells differ by 1
        if row > 0 and is_prime(abs(num +1- grid[row - 1][col])):
            continue  # cell above differs by a prime number
        grid[row][col] = num + 1
        used[num] = True

        if fill_grid(grid, n, m, next_row, next_col, used):
            return True  # found a solution

        grid[row][col] = 0  # backtrack
        used[num] = False

    return False  # no solution found


t = int(input())

for _ in range(t):
   n, m = map(int, input().split())
   grid = [[0] * m for _ in range(n)]
   used = [False] * (n * m)
   fill_grid(grid, n, m, 0, 0, used)

   for row in grid:
      print(*row)
   print()
   
