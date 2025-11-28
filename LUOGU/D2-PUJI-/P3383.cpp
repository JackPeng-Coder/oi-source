#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n, q, cnt = 0;
    cin >> n >> q;
    bool is_prime[n + 1];
    int primes[n + 1];
    memset(is_prime, 1, sizeof(is_prime));

    for(int i = 2; i <= n; i++)
	{
		if(is_prime[i])
        {
            cnt++;
            primes[cnt] = i;
        }

		for(int j = 1; j <= cnt && i * primes[j] <= n; j++) 
		{
			is_prime[i * primes[j]] = 0;
            
			if(i % primes[j] == 0)
				break;
		}
	}

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        cout << primes[x] << endl;
    }
}