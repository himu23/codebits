//in all the number systems, a number with more digits is always greater than the one with less digits(after removing leading zeroes)
// MSB : Most significant bit : the leftmost bit
// LSB : Least significant bit : the rightmost bit
//operations like add, substract, multiply, divide, modulo, etc. are definwd on the vakues of the numbers and not on any particular number system.
//a+b=c will always be true irrespective of which number system a,b and c are represented as.
//but sime operations are specifically defined in the binary number system exclusively.
//these operations are called bitwise operations.
//all the bitwise operators perform operations independently on each bit.
//that is, i-th bit of the output isnt influenced by any bit j(j!=i) of the input.
// AND : A&B=C;   //c is smaller than or equal to min(a,b);
// OR : A|B=C;    //c is greater than or equal to max(a,b);
// XOR : A^B=C;   //cannot say
// 11001000 & 10111000 = 10001000
// 1001000 | 10111000 = 11111000
// xor: 0	0	0
//      0	1	1
//      1	0	1
//      1	1	0

/*
int a=5;
cout<<std::bitset<4>(a);    //101
*/

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int A, B;
    A = 5; // 5 = 101 in Binary
    B = 11; // 11 = 1011 in Binary

    int AND = A & B; // 0101 & 1011
    int OR = A | B; // 0101 | 1011
    int XOR = A ^ B;
    cout << "The Bitwise AND is: " << (A & B) << "\n";
    cout << "The Bitwise OR is: " << (A | B) << "\n";
    cout << "The Bitwise XOR is: "<< (A ^ B)<<endl;
    return 0;
}
/*
The Bitwise AND is: 1
The Bitwise OR is: 15
The Bitwise XOR is: 14

*/
/*
10111 & 101101  //add preciding zeros to fill spaces
10111 ∣ 101101  //101, 111111
*/