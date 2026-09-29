class Solution {
    public boolean hasValidPath(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }

        int len = m + n - 1;

        if (len % 2 == 1) {
            return false;
        }

        byte[][][] dp = new byte[m][n][len + 1];

        return dfs(grid, 0, 0, 0, dp);
    }

    private boolean dfs(char[][] grid, int r, int c, int balance,
                        byte[][][] dp) {

        int m = grid.length;
        int n = grid[0].length;

        if (grid[r][c] == '(') {
            balance++;
        } else {
            balance--;
        }

        if (balance < 0) {
            return false;
        }

        int remaining = (m - 1 - r) + (n - 1 - c);

        if (balance > remaining) {
            return false;
        }

        if (r == m - 1 && c == n - 1) {
            return balance == 0;
        }

        if (dp[r][c][balance] != 0) {
            return dp[r][c][balance] == 1;
        }

        boolean ans = false;

        if (r + 1 < m) {
            ans = dfs(grid, r + 1, c, balance, dp);
        }

        if (!ans && c + 1 < n) {
            ans = dfs(grid, r, c + 1, balance, dp);
        }

        dp[r][c][balance] = (byte) (ans ? 1 : -1);

        return ans;
    }
}