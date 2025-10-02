#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    int sum = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    
    int avg = sum / N;
    int moves = 0;
    
    for (int i = 0; i < N - 1; i++) {
        if (A[i] != avg) {
            int diff = A[i] - avg;
            A[i + 1] += diff;
            moves++;
        }
    }
    
    cout << moves << endl;
    return 0;
}