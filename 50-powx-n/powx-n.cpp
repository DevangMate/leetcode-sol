class Solution {
public:
    double fastPow(double x, long long n) {
    if (n == 0) return 1;

    if (n % 2 == 0) {
        return fastPow(x * x, n / 2);
    }

    return x * fastPow(x, n - 1);
}
    double myPow(double x, int n) {
        long long N = n;   // promote first

    if (N < 0) {
        x = 1 / x;
        N = -N;
    }

    return fastPow(x, N);
    }
};