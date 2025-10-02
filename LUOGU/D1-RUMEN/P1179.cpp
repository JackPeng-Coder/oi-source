#include <iostream>
#include <string>
using namespace std;

int get2(int n)
{
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	if (n % 10 == 2) a = 1;
	if (n / 10 % 10 == 2) b = 1;
	if (n / 100 % 10 == 2) c = 1;
	if (n / 1000 % 10 == 2) d = 1;
	if (n / 10000 % 10 == 2) e = 1;
	return a + b + c + d + e;
}

int main()
{
	int l = 0, r = 0, t = 0;
	cin >> l >> r;
	for (int i = l; i <= r; i++)
	{
		t += get2(i);
		// cout << t << endl;
	}
	cout << t << endl;
}