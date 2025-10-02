#include <iostream>
#include <set>
using namespace std;

int main()
{
    int N, a;
    cin >> N;
    set<int> list;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        list.insert(a);
    }
    cout << list.size() << endl;
    for (auto x : list)
    {
        cout << x << " ";
    }
    cout << endl;
}