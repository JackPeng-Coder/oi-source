#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, min = 10000, max = -1000;
    cin >> n;
    set<int> Set;
    vector<int> Vector(n);
    for (int i = 0; i < n; i++)
    {
        cin >> Vector[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        Set.insert(abs(Vector[i] - Vector[i + 1]));
        // min = min > Vector[i] - Vector[i + 1] ? Vector[i] - Vector[i + 1] : min;
        // max = max < Vector[i] - Vector[i + 1] ? Vector[i] - Vector[i + 1] : max;
    }
    if (Set.size() == n - 1)
    cout << "Jolly" << endl;
    else
    cout << "Not jolly" << endl;
}