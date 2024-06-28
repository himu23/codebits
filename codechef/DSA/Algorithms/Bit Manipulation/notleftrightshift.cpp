// NOT operatior is a unary operator like ++ and -- it is applied on only one operand.
// ~A flips all the bits of A.
// x= 29 = 000000000000000011101
// ~x= -30 = 111111111111111100010
//To calculate the value of a negative number,
//the computer flips all the digits and then adds one.

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int X = 57;
    unsigned int Y = 57;

    cout << "The NOT of X is: " << (~X) << "\n";
    cout << "The NOT of Y is: " << (~Y) << "\n";

//left and right shift

    int A = 341;
    int B = 4;

    int LEFT = A << B;  //equivalent to Ax(2^B)
    int RIGHT = A >> B; //equivalent to A/(2^B)

    cout << "The LEFT shift is: " << LEFT << "\n";
    cout << "The RIGHT shift is: " << RIGHT << "\n";

}

/*
The NOT of X is: -58
The NOT of Y is: 4294967238 == int_max - 57;

The LEFT shift is: 5456
The RIGHT shift is: 21

*/


/*
The Left Shift operator A<<B, shifts the bits of A towards left by B bits.
The leftmost B bits are then padded by zeroes.

11001 (= 25 in decimal)
25 << 3 (25 is shifted towards left by 3 bits)
= 11001000 (= 200 in decimal)

11001 (= 25 in decimal)
25 >> 3 (25 is shifted towards left by 3 bits)
= 11 (= 3 in decimal)
*/