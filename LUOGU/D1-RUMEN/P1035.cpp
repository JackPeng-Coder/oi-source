#include <iostream>
using namespace std;

int main()
{
	double n = 1, r, k;
	cin >> k;
	while (k >= r)
	{
		r += 1/n;
		n++;
	}
	cout << n - 1 << endl;
}