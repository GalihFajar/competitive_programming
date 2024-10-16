#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <list>
using namespace std;

void splice(list<string>& l, int pos) {
    auto it = next(l.begin(), pos - 1);

    l.splice(l.begin(), l, it);
}

string splice_ret(list<string>& l, int pos) {
    auto it = next(l.begin(), pos);
    string temp = *it;
    l.splice(l.begin(), l, it);

    return temp;
}

unordered_map<string, bool> word_map;
list<string> word_list;

bool isDigits(string& s) {
    for (auto c: s) {
        if (c > '9' || c < '0')
            return false;
    }

    return true;
}

string process(string& s) {
    string word = "";
    string ret = "";

    for (int i = 0; i <= (int) s.size(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')
            || (s[i] >= '0' && s[i] <= '9')
        ) {
            word += s[i];
        } else {
            if (!word.empty()) {
                if (isDigits(word)) {
                    string spliced = splice_ret(word_list, stoi(word) - 1);
                    ret += spliced;
                } else {
                    if (!word_map[word]) {
                        word_map[word] = true;
                        word_list.push_front(word);
                        ret += word;
                    }
                }
            }

            if (s[i] != '\0')
                ret += s[i];
            word = "";
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (1) {
        string s; getline(cin, s);
        if (cin.eof() || s == "0") return 0;
        string out = "";
        out += process(s);
        cout << out << '\n';
    }

    return 0;
}
