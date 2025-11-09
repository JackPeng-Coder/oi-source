#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    cin.ignore(); // 忽略换行符

    vector<string> lines(n);
    for (int i = 0; i < n; ++i) {
        getline(cin, lines[i]);
    }

    int aabb = 0, abab = 0, abba = 0;
    int segments = n / 4;

    for (int s = 0; s < segments; ++s) {
        vector<string> rhymes(4);
        bool valid = true;

        for (int i = 0; i < 4; ++i) {
            int line_idx = s * 4 + i;
            string line = lines[line_idx];
            istringstream iss(line);
            vector<string> words;
            string word;
            while (iss >> word) {
                words.push_back(word);
            }
            string last_word = words.back();
            if (last_word.size() < k) {
                valid = false;
                break;
            }
            rhymes[i] = last_word.substr(last_word.size() - k);
        }

        if (!valid) {
            continue;
        }

        // 检查AABB模式
        if (rhymes[0] == rhymes[1] && rhymes[2] == rhymes[3]) {
            aabb++;
        }
        // 检查ABAB模式
        if (rhymes[0] == rhymes[2] && rhymes[1] == rhymes[3]) {
            abab++;
        }
        // 检查ABBA模式
        if (rhymes[0] == rhymes[3] && rhymes[1] == rhymes[2]) {
            abba++;
        }
    }

    cout << aabb << " " << abab << " " << abba << endl;

    return 0;
}