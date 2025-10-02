#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int h, c = 0;
    vector<int> vec(10);
    for (int i = 0; i < 10; i++)
    {
        cin >> vec[i];
    }
    cin >> h;
    for (auto x : vec)
    {
        if (h + 30 >= x) c++;
    }
    cout << c << endl;
}