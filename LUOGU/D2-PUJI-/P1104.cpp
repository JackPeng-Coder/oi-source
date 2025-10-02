#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct student
{
    string name;
    int year, month, day;
    int index; // 添加索引记录输入顺序
};

bool compare(student a, student b)
{
    if (a.year != b.year)
    {
        return a.year < b.year;
    }
    else if (a.month != b.month)
    {
        return a.month < b.month;
    }
    else if (a.day != b.day)
    {
        return a.day < b.day;
    }
    else
    {
        // 生日相同时，输入靠后的同学先输出（索引大的在前）
        return a.index > b.index;
    }
}

int main()
{
    int N;
    cin >> N;
    vector<student> list(N);
    for (int i = 0; i < N; i++)
    {
        cin >> list[i].name >> list[i].year >> list[i].month >> list[i].day;
        list[i].index = i; // 记录输入顺序
    }
    sort(list.begin(), list.end(), compare);
    for (auto s : list)
    {
        cout << s.name << endl;
    }
    return 0;
}