int gcd(int a,int b) { // a >= b
  int R;
  while (b > 0)  {
    R = a % b;
    a = b;
    b = R;
  }
  return a;
}
