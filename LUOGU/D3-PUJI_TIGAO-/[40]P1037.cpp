#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

vector<pair<int, int>> rules;
unordered_set<string> found;

void dfs(string s)
{
    string ns;
    if (found.find(s) != found.end())
    {
        return;
    }
    found.insert(s);
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < rules.size(); j++)
        {
            if (s[i] == rules[j].first + '0')
            {
                ns = s;
                ns[i] = rules[j].second + '0';
                dfs(ns);
            }
        }
    }
}

int main()
{
    string n;
    int  k, a, b;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b;
        rules.push_back({a, b});
    }
    dfs(n);
    cout << found.size() << endl;
}