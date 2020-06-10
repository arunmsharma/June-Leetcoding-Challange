//problem link:-https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3355/
//the main idea here is that if we find lcs betwenn t and s then s should be that lcs. so find the length of longest common subsequence(lcs) and 
//check if the length of that lcs is same as s.length() or not.
class Solution {
public:
    int lcs(string str1,string str2,int a,int b){
        int dp[a+1][b+1];
        for(int i=0;i<=a;i++){
            dp[i][0]=0;
        }
        for(int j=1;j<=b;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[a][b];
    }
    bool isSubsequence(string s, string t) {
        int ans=lcs(t,s,t.length(),s.length());
        return ans==(int)s.length();
    }
};
