#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string, char> digit_map = {
    {"xxxxxx...xx...xx...xx...xx...xxxxxx", '0'},
    {"....x....x....x....x....x....x....x", '1'},
    {"xxxxx....x....xxxxxxx....x....xxxxx", '2'},
    {"xxxxx....x....xxxxxx....x....xxxxxx", '3'},
    {"x...xx...xx...xxxxxx....x....x....x", '4'},
    {"xxxxxx....x....xxxxx....x....xxxxxx", '5'},
    {"xxxxxx....x....xxxxxx...xx...xxxxxx", '6'},
    {"xxxxx....x....x....x....x....x....x", '7'},
    {"xxxxxx...xx...xxxxxxx...xx...xxxxxx", '8'},
    {"xxxxxx...xx...xxxxxx....x....xxxxxx", '9'},
    {".......x....x..xxxxx..x....x.......", '+'}
};

unordered_map<char, vector<string>> digit_str_map = {
    {'0', {"xxxxx", "x...x", "x...x", "x...x", "x...x", "x...x", "xxxxx"}},
    {'1', {"....x", "....x", "....x", "....x", "....x", "....x", "....x"}},
    {'2', {"xxxxx", "....x", "....x", "xxxxx", "x....", "x....", "xxxxx"}},
    {'3', {"xxxxx", "....x", "....x", "xxxxx", "....x", "....x", "xxxxx"}},
    {'4', {"x...x", "x...x", "x...x", "xxxxx", "....x", "....x", "....x"}},
    {'5', {"xxxxx", "x....", "x....", "xxxxx", "....x", "....x", "xxxxx"}},
    {'6', {"xxxxx", "x....", "x....", "xxxxx", "x...x", "x...x", "xxxxx"}},
    {'7', {"xxxxx", "....x", "....x", "....x", "....x", "....x", "....x"}},
    {'8', {"xxxxx", "x...x", "x...x", "xxxxx", "x...x", "x...x", "xxxxx"}},
    {'9', {"xxxxx", "x...x", "x...x", "xxxxx", "....x", "....x", "xxxxx"}},
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<string> inputs;

    for (int i = 0; i < 7; i++) {
        string temp; cin >> temp;
        inputs.push_back(temp);
    }

    int input_length = (int) inputs[0].size() / 5;
    vector<string> inputs_parsed(input_length, "");

    for (int k = 0; k < 7; k++) {
        int cnt = 0;
        for (int i = 0; i < (int) inputs[0].size(); i += 6) {
            string temp = "";
            for (int j = i; j < i + 5; j++) {
                temp += inputs[k][j];
            }

            inputs_parsed[cnt] += temp;
            cnt++;
        }
    }


    string a = "", b = "";
    string* current = &a;
    for (string i: inputs_parsed) {
        char c = digit_map[i];
        if (c == '+') {
            current = &b;
        }

        *current += c;
    }

    int a_int = stoi(a), b_int = stoi(b);
    string summed = to_string(a_int + b_int);

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < (int) summed.size(); j++) {
            cout << digit_str_map[summed[j]][i];
            if (j != (int) summed.size() - 1)
                cout << ".";
        }
        cout << '\n';
    }

    return 0;
}
