#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<double> teamsfinal(26);

bool cmp(pair<int, char> student1, pair<int, char> student2)
{
    int score1 = round(student1.first * 0.6 + round(teamsfinal[student1.second - 'A']) * 0.4);
    int score2 = round(student2.first * 0.6 + round(teamsfinal[student2.second - 'A']) * 0.4);
    
    if (score1 != score2) {
        return score1 > score2;
    } else {
        return student1.second < student2.second;
    }
}

int main()
{
    int n, k, sum;
    double avg;
    cin >> n >> k;
    vector<pair<int, char>> students(n);
    vector<vector<int>> teams(k, vector<int>(k));

    for (int i = 0; i < n; i++)
    {
        cin >> students[i].first >> students[i].second;
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> teams[i][j];
        }
    }

    for (int i = 0; i < k; i++)
    {
        avg = 0;
        for (int j = 0; j < k; j++)
        {
            avg += teams[j][i];
        }
        teamsfinal[i] = avg / k;
    }

    for (int i = 0; i < k; i++)
    {
        avg = 0;
        sum = 0;
        for (int j = 0; j < k; j++)
        {
            if (abs(teams[j][i] - teamsfinal[i]) <= 15)
            {
                avg += teams[j][i];
                sum++;
            }
        }
        teamsfinal[i] = avg / sum;
    }

    sort(students.begin(), students.end(), cmp);

    for (auto student : students)
    {
        cout << round(student.first * 0.6 + round(teamsfinal[student.second - 'A']) * 0.4) << " " << student.second << endl;
    }

}