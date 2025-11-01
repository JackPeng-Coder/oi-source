#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    long long n;
    long long min = numeric_limits<long long>::max();
    cin >> n;
    vector<pair<long long, long long>> vec(n);
    for (long long i = 0; i < n; i++) {
        cin >> vec[i].first >> vec[i].second;
    }
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < i; j++) {
            long long d2 = (vec[i].first - vec[j].first) * (vec[i].first - vec[j].first) + (vec[i].second - vec[j].second) * (vec[i].second - vec[j].second);
            if (d2 < min) min = d2;
        }
    }
    cout << fixed << setprecision(4) << sqrt(min) << endl;
}