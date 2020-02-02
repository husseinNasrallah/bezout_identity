
#include <iostream>
using namespace std;
long long bezout(long long m, long long n, long long* a, long long* b);
//a program that uses the bezout identiy on the 2 given numbers
int main() {
	//initialize the variables
	long long m;
	long long n;
	long long x = 0;
	long long y = 0;
	long long* a = &x;
	long long* b = &y;
	long long gcd = 1;
	//get the values of m and n
	cout << "enter the integer m " << endl;
	cin >> m;
	cout << "enter the integer n " << endl;
	cin >> n;
	//call the funciton
	gcd = bezout(m, n, a, b);
	cout << "the gcd is " << gcd << endl;
	cout << *a << " * "<<m<<" +(" << *b << ") * "<<n<<" = " << gcd;
}
//function that does the bezout identity of 2 numbers

long long bezout(long long m, long long n, long long* a, long long* b) {
	long long s = 0; long long old_s = 1;
	long long t = 1; long long old_t = 0;
	long long r = n; long long old_r = m;
	while (r != 0) {
		long long quotient = old_r / r;
		// We are overriding the value of r, before that we store it"s current
		// value in temp variable, later we assign it to old_r
		long long temp = r;
		r = old_r - quotient * r;
		old_r = temp;

		// We treat s and t in the same manner we treated r
		temp = s;
		s = old_s - quotient * s;
		old_s = temp;

		temp = t;
		t = old_t - quotient * t;
		old_t = temp;
		
	}
	*a = old_s;
	*b = old_t;
	return old_r;
}
