//problem link:-https://leetcode.com/explore/featured/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3364/
class Solution {
public:
    int hIndex(vector<int>& citations) {
         int n=citations.size();   
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(citations[mid]>=(n-mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return n-low;
    }
};
