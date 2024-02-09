/* Problem statement: 
	 Perform sum of two integers without using '+' operations */

#include <bits/stdc++.h>
using namespace std;

int main () { 
  int a, b;
  cin >> a >> b;
  while (b) { 
    int sum = a ^ b;
    int carry = (a & b) << 1;
    a = sum;
    b = carry;
  }
  cout << a << '\n';
  return 0;
}
