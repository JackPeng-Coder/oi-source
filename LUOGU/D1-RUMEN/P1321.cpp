#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int boy = 0, girl = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (
            (s[i] == 'b') || 
            (i >= 1 && s[i] == 'o' && s[i - 1] != 'b') ||
            (i >= 2 && s[i] == 'y' && s[i - 1] != 'o' && s[i - 2] != 'b')
        ) boy += 1;
        if (
            (s[i] == 'g') || 
            (i >= 1 && s[i] == 'i' && s[i - 1] != 'g') ||
            (i >= 2 && s[i] == 'r' && s[i - 1] != 'i' && s[i - 2] != 'g') ||
            (i >= 3 && s[i] == 'l' && s[i - 1] != 'r' && s[i - 2] != 'i' && s[i - 3] != 'g')
        ) girl += 1;
    }
    cout << boy << endl << girl << endl;
}