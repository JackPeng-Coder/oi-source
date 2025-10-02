#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int current = 0;
    int max_sum = a[0];
    for (int i = 0; i < n; i++) {
        current += a[i];
        if (current > max_sum) {
            max_sum = current;
        }
        if (current < 0) {
            current = 0;
        }
    }
    cout << max_sum << endl;
    return 0;
}