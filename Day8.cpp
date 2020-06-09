/* problem link-https://leetcode.com/explore/featured/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3354/  */
class Solution {
public:
    bool isPowerOfTwo(long long n) {
       return (n and (n&(n-1))==0);
    }
};
