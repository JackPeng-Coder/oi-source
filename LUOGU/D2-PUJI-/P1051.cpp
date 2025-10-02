#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct student
{
    string name;
    int finalmark;
    int classmark;
    char monitor;
    char western;
    int papernum;
};

void calcmoney(vector<student> students)
{
    string maxname;
    int money, maxmoney = 0, totalmoney = 0;

    for (auto student : students)
    {
        money = 0;
        if (student.finalmark > 80 && student.papernum >= 1)
            money += 8000;
        if (student.finalmark > 85 && student.classmark > 80)
            money += 4000;
        if (student.finalmark > 90)
            money += 2000;
        if (student.finalmark > 85 && student.western == 'Y')
            money += 1000;
        if (student.classmark > 80 && student.monitor == 'Y')
            money += 850;

        if (money > maxmoney)
        {
            maxmoney = money;
            maxname = student.name;
        }
        totalmoney += money;
    }
    cout << maxname << endl << maxmoney << endl << totalmoney << endl;
}

int main()
{
    int N;
    cin >> N;
    vector<student> students(N);
    for (int i = 0; i < N; i++)
    {
        cin >> students[i].name >> students[i].finalmark >> students[i].classmark >> students[i].monitor >> students[i].western >> students[i].papernum;
    }
    calcmoney(students);
}