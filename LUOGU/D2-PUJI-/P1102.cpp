#include <iostream>
#include <map>
using namespace std;

int main() {
    int N, C;
    cin >> N >> C;
    map<int, int> freq;
    int *arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }
    long long count = 0;
    for (int i = 0; i < N; i++) {
        int target = arr[i] + C;
        count += freq[target];
    }
    cout << count << endl;
    return 0;
}