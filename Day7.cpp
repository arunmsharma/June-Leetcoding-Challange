//problem link:-https://leetcode.com/explore/featured/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3353/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[5001]={0};
        dp[0]=1;
        int n=coins.size();
        for(int i=0;i<n;i++){
            int coin=coins[i];
            for(int j=1;j<=amount;j++){
                if(j>=coin){
                    dp[j]+=dp[j-coin];
                }
            }
        }
        return dp[amount];
    }
};
