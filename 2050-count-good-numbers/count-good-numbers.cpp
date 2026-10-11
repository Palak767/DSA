class Solution {
public:
long long MOD = 1e9 + 7;
    long long power(long long base, long long exp){
        if(exp == 0) return 1;
        base %= MOD;
        long long half = power(base,exp/2);
        if(exp % 2 == 0){
            return (half * half) % MOD;
        }else{
            return (((half * half) % MOD) * base) % MOD;
        }
    }
    int countGoodNumbers(long long n) {
        long long evenCnt = (n+1)/2;
        long long oddCnt = n/2;
        long long waysEven = power(5,evenCnt);
        long long waysOdd = power(4,oddCnt);
        return (waysEven * waysOdd) % MOD;
    }
};