#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string key, cipher;
    cin >> key >> cipher;
    
    int key_len = key.length();
    int cipher_len = cipher.length();
    
    int key_num[100];
    for (int i = 0; i < key_len; i++) {
        key_num[i] = toupper(key[i]) - 'A';
    }
    
    int key_index = 0;
    for (int i = 0; i < cipher_len; i++) {
        char ch = cipher[i];
        bool is_upper = isupper(ch);
        int c_num = toupper(ch) - 'A';
        int k_num = key_num[key_index];
        
        int m_num = (c_num - k_num + 26) % 26;
        char plain_char = 'A' + m_num;
        
        if (!is_upper) {
            plain_char = tolower(plain_char);
        }
        
        cout << plain_char;
        
        key_index = (key_index + 1) % key_len;
    }
    
    cout << endl;
    
    return 0;
}