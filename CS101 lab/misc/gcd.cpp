#include<simplecpp>
int gcd(int a,int b){
    if(b==0)
    return a;
    else
    return gcd(b,a%b);
}
main_program{

}