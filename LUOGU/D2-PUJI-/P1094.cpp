#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int w, n, cnt = 0;
    cin >> w >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int i = 0, j = n - 1;
    while (i < j) {
        if (a[i] + a[j] <= w) {
            i++;
            j--;
            cnt++;
        } else {
            j--;
            cnt++;
        }
    }
    if (i == j) cnt++;
    cout << cnt << endl;
}