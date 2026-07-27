class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:

        dp=[]
        maxi=0

        m,n=len(matrix),len(matrix[0])

        for i in range(m+1):
            dp.append([0]*(n+1))

        for i in range(m-1,-1,-1):

            for j in range(n-1,-1,-1):

                if matrix[i][j]=='1':

                    dp[i][j]=1+min(
                        dp[i][j+1],
                        dp[i+1][j],
                        dp[i+1][j+1]
                    )

                maxi=max(maxi,dp[i][j])

        return maxi*maxi