#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[105];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                count++;
            }
        }
        cout << count << " ";
    }
    
    return 0;
}