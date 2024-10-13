#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<string> qwerty = {
    {"`1234567890-="},
    {"qwertyuiop[]\\"},
    {"asdfghjkl;'"},
    {"zxcvbnm,./"},
};

vector<string> qwerty_shift = {
    {"~!@#$%^&*()_+"},
    {"QWERTYUIOP{}|"},
    {"ASDFGHJKL:\""},
    {"ZXCVBNM<>?"},
};

vector<string> dvorak = {
    {"`123qjlmfp/[]"},
    {"456.orsuyb;=\\"},
    {"789aehtdck-"},
    {"0zx,inwvg'"},
};

vector<string> dvorak_shift = {
    {"~!@#QJLMFP?{}"},
    {"$%^>ORSUYB:+|"},
    {"&*(AEHTDCK_"},
    {")ZX<INWVG\""},
};

char to_dvorak(char qw_char) {
    for (int i = 0; i < (int) qwerty.size(); i++) {
        for (int j = 0; j < (int) qwerty[0].size(); j++) {
            if (qw_char == qwerty[i][j])
                return dvorak[i][j];

            if (qw_char == qwerty_shift[i][j])
                return dvorak_shift[i][j];
        }
    }

    return qw_char;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while(1) {
        string s;
        getline(cin, s);
        if (cin.eof()) return 0;

        for (char c: s) {
            cout << to_dvorak(c);
        }
        cout << '\n';
    }


    return 0;
}
