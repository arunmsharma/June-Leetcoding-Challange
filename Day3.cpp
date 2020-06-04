//problem link:- https://leetcode.com/explore/featured/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3349/
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        //Greedy 
        vector<pair<int,int>>v;//vector of abs and index
        for(int i=0;i<costs.size();i++){
            int x=(costs[i][0]-costs[i][1]);
            v.push_back({x,i});
        }
        sort(v.begin(),v.end());
        int ans=0;
        for(int i=0;i<v.size()/2;i++){
            ans+=costs[v[i].second][0];
        }
        for(int i=v.size()/2;i<v.size();i++){
            ans+=costs[v[i].second][1];
        }
        return ans;
    }
};
