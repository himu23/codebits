/*
Fast exponentiation (also known as exponentiation by squaring) is a trick which allows to calculate   a^n  using only   O(log⁡n) multiplications
 (instead of   O(n)  multiplications required by the naive approach).
 It also has important applications in many tasks unrelated to arithmetic, since it can be used with any operations that have the property of associativity:
(X⋅Y)⋅Z=X⋅(Y⋅Z)*/
/*
  3^13=3^1101.2=3^8⋅3^4⋅3^1=6561⋅81⋅3=1594323  Since the number n has exactly  ⌊log⁡2n⌋+1 digits in base 2, we only need to perform   O(log⁡n) multiplications, if we know the powers   a^1,a^2,a^4,a^8,…,a^2^⌊log⁡n⌋.*/
int fastpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

//Effective computation of large exponents modulo a number
//Since we know that the modulo operator doesn't interfere with multiplications (  a⋅b≡(a mod m)⋅(b mod m)(modm) ), we can directly use the same code, and just replace every multiplication with a modular multiplication:
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}