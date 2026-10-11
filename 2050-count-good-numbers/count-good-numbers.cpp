class Solution {
public:
long long MOD = 1e9 + 7;
    long long power(long long base, long long exp){
        long long res = 1;
        base %= MOD;
        while(exp > 0){
            if(exp % 2 == 1){
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long evenCnt = (n+1)/2;
        long long oddCnt = n/2;
        long long waysEven = power(5,evenCnt);
        long long waysOdd = power(4,oddCnt);
        return (waysEven * waysOdd) % MOD;
    }
};