#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int year, int month) {
    static int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (month == 2 && isLeap(year)) return 29;
    return days[month - 1];
}

long long toMinutes(int year, int month, int day, int hour, int minute) {
    long long minutes = 0;
    for (int y = 0; y < year; y++) {
        minutes += (isLeap(y) ? 366 : 365) * 24LL * 60;
    }
    for (int m = 1; m < month; m++) {
        minutes += daysInMonth(year, m) * 24LL * 60;
    }
    minutes += (day - 1) * 24LL * 60;
    minutes += hour * 60LL + minute;
    return minutes;
}

void parseTime(const string& timeStr, int &year, int &month, int &day, int &hour, int &minute) {
    sscanf(timeStr.c_str(), "%d-%d-%d-%d:%d", &year, &month, &day, &hour, &minute);
}

int main() {
    int N;
    cin >> N;
    vector<int> times(N);
    for (int i = 0; i < N; i++) cin >> times[i];

    sort(times.begin(), times.end());

    string t1, t2;
    cin >> t1 >> t2;

    int y1,m1,d1,h1,min1;
    int y2,m2,d2,h2,min2;

    parseTime(t1, y1,m1,d1,h1,min1);
    parseTime(t2, y2,m2,d2,h2,min2);

    long long minutes1 = toMinutes(y1,m1,d1,h1,min1);
    long long minutes2 = toMinutes(y2,m2,d2,h2,min2);

    long long diff = minutes2 - minutes1;
    if (diff <= 0) { cout << 0 << endl; return 0; }

    int sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (sum + times[i] > diff) break;
        sum += times[i];
        count++;
    }

    cout << count << endl;
    return 0;
}
