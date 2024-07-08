//modular multiplicative inverse
/*of an integer a is an integer  x such that a⋅x is congruent to 1 modular some modulus m. To write it in a formal way: we want to find an integer x so that
a⋅x≡1 mod  m. We will also denote x simply with a^−1.*/
/*It can be proven that the modular inverse exists if and only if a and m are relatively prime (i.e. gcd⁡(a,m)=1).*/
/*
//Fermat little theorem

It states that if p is a prime number, then for any integer a, the number ap–aap–a is an integer multiple of p.

    a^p≡a(modp)

It can also be converted into different states that ap−1−1ap−1−1 is an integer multiple of p.

    a^p−1≡1 (mod p) or a^p−1 % p = 1


We can find inverse using fermat's little theorem According to fermat' litte theorem

    a^m−1= 1 (mod m)

Multiplying both side by a−1a−1

    a^−1 ≡ a^m−2(mod m)

    only those a which are coprime with m will have an inverse.

*/