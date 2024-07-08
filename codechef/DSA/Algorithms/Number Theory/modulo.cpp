/*
if we take m=21m=21, then instead of working with x = 247, we use x mod 21 = 16, 247 mod 21 is 16 due to the remainder left when 247 is divided by 21.
Usually, m will be a large prime, given in the problem; the two most common values are 10^9+7, and 998244353. Modular arithmetic is used to avoid dealing with numbers that overflow built-in data types, because we can take remainders. 

(a+b)modm=(amodm+bmodm)modm

(a−b) mod m=(a mod m−b mod m) mod m

(a⋅b)(modm)=((a mod m)⋅(b mod m)) mod m

a^b mod m=(a mod m)^b mod m
*/