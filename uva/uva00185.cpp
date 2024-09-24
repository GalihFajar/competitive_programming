#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef unordered_map<char, int> uci;
typedef unordered_map<char, bool> ucb;
typedef unordered_set<char> usc;

template <typename T>
bool find(unordered_set<T> us, T in) {
    if (us.find(in) != us.end())
        return true;
    return false;
}

template <typename K, typename T>
void print_unordered(unordered_map<K, T>& us) {
    cout << '[' << endl;
    for (auto u: us) {
        cout << "\t{" << u.first << " " << u.second << "}" << endl;
    }
    cout << ']' << endl;
};

uci roman_int_map = {
    {'M', 1000},
    {'C', 100},
    {'X', 10},
    {'I', 1},
    {'D', 500},
    {'L', 50},
    {'V', 5}
};

ucb roman_can_repeat = {
    {'M', true},
    {'C', true},
    {'X', true},
    {'I', true}
};

bool is_valid_roman(string& s) {
    // check repeat
    auto is_repeat = [s] {
        uci char_count;
        uci streak;
        usc char_set;

        int i = 0;
        while (i < (int) s.size()) {
            char_set.insert(s[i]);
            if (i == 0) {
                char_count[s[i]]++;
                i++;
                streak[s[i]] = 1;
                continue;
            }

            char_count[s[i]]++;
            if (s[i] != s[i - 1])
                streak[s[i]] = 1;
            else
                streak[s[i]]++;

            i++;
        }

        for (char c: char_set) {
            if (streak[c] >= 2 && !roman_can_repeat[c])
                return false;
            if (streak[c] >= 4)
                return false;
            if (streak[c] == 3 && char_count[c] >= 5)
                return false;
        }

        return true;
    };

    // check negative pos
    auto is_neg_valid = [s] {
        int i = 0;
        bool is_neg = false;
        char curr_max_char;

        while (i < (int) s.size()) {
            if (is_neg && roman_int_map[s[i]] > roman_int_map[curr_max_char])
                return false;

            if (i == s.size() - 1) {
                i++;
                continue;
            }

            if (roman_int_map[s[i]] < roman_int_map[s[i + 1]]) {
                is_neg = true;
                curr_max_char = s[i];
                i++;
            }

            i++;
        }

        return true;
    };

    return is_repeat() && is_neg_valid();
}

int roman_to_ar(string& s) {
    int i = 0;
    int ret = 0;

    while (i < (int) s.size() - 1) {
        if (roman_int_map[s[i]] < roman_int_map[s[i + 1]]) {
            ret += roman_int_map[s[i + 1]] - roman_int_map[s[i]];
            i += 2;
            continue;
        }

        ret += roman_int_map[s[i]];
        i++;
    }

    ret += roman_int_map[s[i]];

    return ret;
}

// as+ad=aaa

vector<string> parse_input(string& s) {
    char plus_pos, equal_pos;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+')
            plus_pos = i;
        if (s[i] == '=')
            equal_pos = i;
    }

    string s1 = s.substr(0, plus_pos);
    string s2 = s.substr(plus_pos + 1, equal_pos - plus_pos - 1);
    string s3 = s.substr(equal_pos + 1, s.length() - equal_pos);


    return {s1, s2, s3};
}

void backtrack(vector<char>& v, vector<string>& out, uci& pot, vector<bool>& is_used, vector<string>& input, int idx) {
    if (idx >= v.size()) {
        // print_unordered(pot);
        // check
        auto maps = [&pot] (string& s) {
            int multiplier = 1;
            int ret = 0;

            for (int i = s.size() - 1; i >= 0; i--) {
                char c = s[i];
                ret += pot[c] * multiplier;
                multiplier *= 10;
            }

            return ret;
        };

        auto maps_string = [&pot] (string& s) {
            string out = "";
            for (int i = 0; i < (int) s.size(); i++) {
                char c = pot[s[i]] + '0';
                out += c;
            }

            return out;
        };

        int s1 = maps(input[0]), s2 = maps(input[1]), s3 = maps(input[2]);


        if (s3 == s1 + s2) {
            if (to_string(s1) == maps_string(input[0]) && to_string(s2) == maps_string(input[1]) && to_string(s3) == maps_string(input[2]))
                out.push_back("true");
        }
    } else {
        char temp_c = v[idx];
        for (int i = 0; i < 10; i++) {
            if (is_used[i])
                continue;

            pot[temp_c] = i;
            is_used[i] = true;
            backtrack(v, out, pot, is_used, input, idx + 1);
            pot.erase(temp_c);
            is_used[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (1) {
        string input;
        cin >> input;
        if (input == "#" || cin.eof())
            return 0;

        auto parsed_input = parse_input(input);
        if (roman_to_ar(parsed_input[0]) + roman_to_ar(parsed_input[1]) == roman_to_ar(parsed_input[2])) {
            cout << "Correct ";
        } else {
            cout << "Incorrect ";
        }

        usc temp;
        vector<char> temp_v;
        for (auto c: input) {
            if (c != '=' && c != '+')
                temp.insert(c);
        }

        for (char c: temp) {
            temp_v.push_back(c);
        }

        vector<string> out;
        uci temp_uci;
        vector<bool> is_used(10);

        backtrack(temp_v, out, temp_uci, is_used, parsed_input, 0);

        if ((int) out.size() == 1)
            cout << "valid" << endl;
        else if (out.size() == 0)
            cout << "impossible" << endl;
        else
            cout << "ambiguous" << endl;
    }

    return 0;
}
