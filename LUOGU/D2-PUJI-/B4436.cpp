#include <bits/stdc++.h>
using namespace std;

string sort(string str)
{
    char t;
    bool run;
    do
    {
        run = false;
        for (int i = 0; i < str.length() - 1; i++)
        {
            if (str[i] > str[i+1])
            {
                t = str[i];
                str[i] = str[i+1];
                str[i+1] = t;
                run = true;
            }
        }
    } while (run);
    return str;
}
 
string erase(string str, int index)
{
    string result = "";
    for (int i = 0; i < str.length(); i++)
        if (i != index) result += str[i];
    return result;
}
 
vector<string> myfunction(string str)
{
    vector<string> vec;
    if (str.length() == 1)
    {
        vec.push_back(str);
    }
    else
    {
        for (int i = 0; i < str.length(); i++)
        {
            vector<string> child = myfunction(erase(str, i));
            for (int j =0; j < child.size(); j++)
            {
                string s = "";
                s.push_back(str[i]);
                vec.push_back(s + child[j]);
            }
        }
    }
    return vec;
}
 
int main() {
    int n, s = 0, index = 0;
    cin >> n;
    string s2 = "";
    for (int i = 1; i <= n; i++) {
        s2 += i + '0';
    }
    vector<string> vec = myfunction(s2);
    while (s == 0) {
        cout << endl;
        for (int i = 0; i < n; i++) {
            cout << vec[index][i] << " ";
        }
        cout << endl;
        cin >> s;
        if (s == 1) {
            break;
        }
        index++;
    }
}
