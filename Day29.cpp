class Solution {
public:
    long long int ncr(int n,int r){
        long long p=1,k=1;
        if(n-r<r){
            r=n-r;
        }
        if(r!=0){
            while(r){
                p*=n;
                k*=r;
                long long m=__gcd(p,k);
                p/=m;
                k/=m;
                --n;
                --r;
            }
        }
        else{
            p=1;
        }
        return p;
    }
    long long  uniquePaths(int m, int n) {
        --m,--n;
        return ncr(m+n,n);
    }
};
