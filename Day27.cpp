class Solution {
public:
    int numSquares(int n) 
    {
        if (n <= 0)
        {
            return 0;
        }
        
        //dp[i] = the least number of perfect square numbers 
        // which sum to i. Note that dp[0] is 0.
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            // For each i, it must be the sum of some number (i - j*j) and 
            // a perfect square number (j*j).
            for (int j = 1; j*j <= i; j++)
            {
                dp[i] = 
                    min(dp[i], dp[i - j*j] + 1);
            }
        }
        
        return dp.back();
    }
};
