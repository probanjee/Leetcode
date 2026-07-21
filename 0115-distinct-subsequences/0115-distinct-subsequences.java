class Solution {
    private int count(int i, int j, String s, String t, int[][] memo) {
        if (j == 0) return 1;
        if (i == 0) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        memo[i][j] = count(i - 1, j, s, t, memo);
        if (s.charAt(i - 1) == t.charAt(j - 1)) {
            memo[i][j] += count(i - 1, j - 1, s, t, memo);
        }
        return memo[i][j];
    }

    public int numDistinct(String s, String t) {
  
        int m = s.length(), n = t.length();
        if (n > m) return 0;
        int[] dp = new int[n + 1];
        dp[0] = 1;
        for (int i = 1; i <= m; ++i) {
            int prevDiag = dp[0];
            for (int j = 1; j <= n; ++j) {
                int temp = dp[j];
                if (s.charAt(i - 1) == t.charAt(j - 1)) {
                    dp[j] += prevDiag;
                }
                prevDiag = temp;
            }
        }
        return dp[n];
    }
}