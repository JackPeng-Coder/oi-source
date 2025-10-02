#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const string& a, const string& b) {
    return a + b > b + a;
}

int main()
{
    int n;
    cin >> n;
    vector<string> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end(), compare);
    for (auto s : vec)
    {
        cout << s;
    }
    cout << endl;
}