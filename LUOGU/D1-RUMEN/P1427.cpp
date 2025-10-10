#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a = 1;
    vector<int> v;
    while (a != 0)
    {
        cin >> a;
        if (a != 0) v.push_back(a);
    }
    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i] << " ";
    }
}