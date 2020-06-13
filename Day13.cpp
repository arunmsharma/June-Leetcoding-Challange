//problem link:-https://leetcode.com/explore/featured/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3359/
class Solution {
    void init(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        init();
        if(nums.size()==0){
            vector<int>v(0);
            return v;
        }
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> adj[n];
        int dp[n];
        
        memset(dp,1,sizeof(dp));
        
        for(int i=0;i<n;i++){
            adj[i].push_back(nums[i]);
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[j]%nums[i]==0){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        adj[i].clear();
                        adj[i].push_back(nums[i]);
                        adj[i].insert(adj[i].end(),adj[j].begin(),adj[j].end());
                    }
                }
            }
        }
        
        int index=-1;
        int max=-1;
        for(int i=0;i<n;i++){
            if(dp[i]>max){
                index=i;
                max=dp[i];
            }
        }
        return adj[index];
    }
};
