class Solution {
    vector<int>prefix;
    int sum = 0;
public:
    Solution(vector<int>& w) {
        for(int x: w){
            sum+=x;
            prefix.push_back(sum);
            }
    }
    
    int pickIndex() {
        int val = rand()%sum + 1;
        return lower_bound(prefix.
                           begin(),prefix.end(),val)-prefix.
            begin ();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
