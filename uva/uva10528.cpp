#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

template <typename T>
void print_set(unordered_set<T>& set) {
    cout << "{ ";
    for (auto elem: set) {
        cout << elem << " ";
    }
    cout << "}\n";
}

template <typename T>
void print_sets(vector<unordered_set<T>>& sets) {
    cout << "[\n";
    for (auto us: sets) {
        print_set<T>(us);
    }
    cout << "]\n";
}

template <typename T>
bool elem_exist(unordered_set<T>& set, T& query) {
    return set.find(query) != set.end();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<unordered_set<string>> scales(12);
    vector<string> c_scale{"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

    for (int i = 0; i < 12; i++) {
        int j = i;
        int count = 1;
        unordered_set<string> s;

        while ((int) s.size() < 7) {
            s.insert(c_scale[j % 12]);

            if (count == 3 || count == 7)
                j++;
            else
                j += 2;

            count++;
        }

        scales[i] = s;
    }

    while (1) {
        string input;
        getline(cin, input);

        if (input == "END") return 0;
        vector<string> keys;
        vector<int> correct_scales(12, true);

        string temp = "";
        for (int i = 0; i < (int) input.size(); i++) {
            if (input[i] != ' ') {
                temp += input[i];
            } else {
                keys.push_back(temp);
                temp = "";
            }
        }
        if (!temp.empty()) keys.push_back(temp);

        for (string key: keys) {
            for (int i = 0; i < (int) scales.size(); i++) {
                if (!elem_exist(scales[i], key)) {
                    correct_scales[i] = false;
                }
            }
        }

        bool first = true;
        for (int i = 0; i < (int) correct_scales.size(); i++) {
            if (first && correct_scales[i]) {
                first = false;
                cout << c_scale[i];
            } else if (correct_scales[i]) {
                cout << " " << c_scale[i];
            }
        }

        cout << '\n';
    }

    return 0;
}
