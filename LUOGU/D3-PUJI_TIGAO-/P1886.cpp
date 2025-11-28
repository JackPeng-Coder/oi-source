#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> min(n), max(n);
    deque<int> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        while (!q.empty() && a[q.back()] >= a[i]) {
            q.pop_back();
        }
        q.push_back(i);
        if (i - q.front() >= k) {
            q.pop_front();
        }
        if (i >= k - 1) {
            min[i - k + 1] = a[q.front()];
        }
    }
    q.clear();
    for (int i = 0; i < n; i++) {
        while (!q.empty() && a[q.back()] <= a[i]) {
            q.pop_back();
        }
        q.push_back(i);
        if (i - q.front() >= k) {
            q.pop_front();
        }
        if (i >= k - 1) {
            max[i - k + 1] = a[q.front()];
        }
    }
    for (int i = 0; i < n - k + 1; i++) {
        cout << min[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n - k + 1; i++) {
        cout << max[i] << " ";
    }
    cout << endl;
}