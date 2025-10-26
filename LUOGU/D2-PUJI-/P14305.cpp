#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, string> MAP = {
    {"charchar", "int"},
    {"charbool", "int"},
    {"charint", "int"},
    {"charlonglong", "longlong"},
    {"charfloat", "float"},
    {"chardouble", "double"},
    {"boolchar", "int"},
    {"boolbool", "int"},
    {"boolint", "int"},
    {"boollonglong", "longlong"},
    {"boolfloat", "float"},
    {"booldouble", "double"},
    {"intchar", "int"},
    {"intbool", "int"},
    {"intint", "int"},
    {"intlonglong", "longlong"},
    {"intfloat", "float"},
    {"intdouble", "double"},
    {"longlongchar", "longlong"},
    {"longlongbool", "longlong"},
    {"longlongint", "longlong"},
    {"longlonglonglong", "longlong"},
    {"longlongfloat", "float"},
    {"longlongdouble", "double"},
    {"floatchar", "float"},
    {"floatbool", "float"},
    {"floatint", "float"},
    {"floatlonglong", "float"},
    {"floatfloat", "float"},
    {"floatdouble", "double"},
    {"doublechar", "double"},
    {"doublebool", "double"},
    {"doubleint", "double"},
    {"doublelonglong", "double"},
    {"doublefloat", "double"},
    {"doubledouble", "double"}
};

string calc(string a, string b) {
    if (a == "char" || a == "bool") a = "int";
    if (b == "char" || b == "bool") b = "int";
    return MAP[a + b];
}

vector<string> split_add(string s) {
    vector<string> v = {""};
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+') {
            v.push_back("");
        }
        else {
            v.back() += s[i];
        }
    }
    return v;
}

vector<string> split_times(string s) {
    vector<string> v = {""};
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '*') {
            v.push_back("");
        }
        else {
            v.back() += s[i];
        }
    }
    return v;
}

string merge(vector<string> v) {
    if (v.size() == 1) return v[0];
    else if (v.size() == 2) return calc(v[0], v[1]);
    
    string res = calc(v[0], v[1]);
    for (int i = 2; i < v.size(); i++) {
        res = calc(res, v[i]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c, T;
    string s;
    cin >> c >> T;
    while (T--) {
        cin >> s;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ',') {
                s = s.substr(i + 1);
                break;
            }
        }
        vector<string> v = split_add(s);
        for (int i = 0; i < v.size(); i++) {
            v[i] = merge(split_times(v[i]));
        }
        cout << merge(v) << endl;
    }
}