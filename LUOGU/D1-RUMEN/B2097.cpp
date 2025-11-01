#include <iostream>
using namespace std;

int main() {
    int n, last, current, sum = 1, max = 1;
    cin >> n;
    cin >> current;
    for (int i = 1; i < n; i++) {
        last = current;
        cin >> current;
        if (last == current) sum++;
        else sum = 1;
        if (max < sum) max = sum;
    }
    cout << max << endl;
}