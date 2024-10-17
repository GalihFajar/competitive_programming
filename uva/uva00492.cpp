#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;


vector<char> vowels = {'a', 'i', 'e', 'o', 'u', 'A', 'I', 'E', 'O', 'U'};

bool isOnlyLatin(string& s) {
    for (char c: s) {
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
            return false;
    }

    return true;
}


void convert(string& s) {
    if (s.empty()) return;

    for (auto v: vowels) {
        if (s[0] == v) {
            s += "ay";
            return;
        }
    }

    string temp = s.substr(1, (int) s.size() - 1);
    temp += s[0];
    temp += "ay";

    s = temp;
}

string process(string& s) {
    string ret = "";
    string word = "";

    for (int i = 0; i <= (int) s.size(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            word += s[i];
        } else {

            convert(word);
            ret += word;
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
        string s;

        getline(cin, s);
        if (cin.eof()) return 0;

        cout << process(s) << '\n';
    }

    return 0;
}
