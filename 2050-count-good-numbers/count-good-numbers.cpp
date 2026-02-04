class Solution {
public:
const int MOD = 1e9 + 7;

long long power(long long base, long long exp) {
    long long result = 1;
    base %= MOD;

    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % MOD;

        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}
    int countGoodNumbers(long long n) {
         long long evenPositions = (n + 1) / 2;
    long long oddPositions  = n / 2;

    long long ans = power(5, evenPositions);
    ans = (ans * power(4, oddPositions)) % MOD;

    return (int)ans;
    }
};