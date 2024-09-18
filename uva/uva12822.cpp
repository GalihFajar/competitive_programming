#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<int, int> score_map = {
    {0, 6},
    {1, 2},
    {2, 5},
    {3, 5},
    {4, 4},
    {5, 5},
    {6, 6},
    {7, 3},
    {8, 7},
    {9, 6}
};


vector<int> parse_clock(string s) {
    vector<int> ret;
    ret.push_back(stoi(s.substr(0, 2)));
    ret.push_back(stoi(s.substr(3, 2)));
    ret.push_back(stoi(s.substr(6, 2)));

    return ret;
}

template<typename T>
void print_vector(vector<T> v) {
    for (auto x: v) {
        cout << x << endl;
    }
}

vector<string> parse_score_or_end(string& s) {
    vector<string> ret;
    string current = "";
    int idx = 0;

    while (idx < s.size()) {
        if (s[idx] == ' ') {
            ret.push_back(current);
            current = "";
        } else {
            current += s[idx];
        }
        idx++;
    }

    ret.push_back(current);

    return ret;
}


int current_score_map(int score) {
    if (score == 0)
        return score_map[0];

    int ret = 0;
    while (score > 0) {
        ret += score_map[score % 10];
        score /= 10;
    }

    return ret;
}


void increment_power(int& current_score, vector<int>& v_clock, vector<string>& input, int& power) {
    // cout << "called." << endl;
    vector<int> clock = parse_clock(input[1]);
    // int seconds_elapsed = (clock[0] - v_clock[0]) * 3600 + (clock[1] - v_clock[1]) * 60 + (clock[2] - v_clock[2]);
    int seconds_elapsed = (clock[0] * 3600 + clock[1] * 60 + clock[2]) - (v_clock[0] * 3600 + v_clock[1] * 60 + v_clock[2]);
    // cout << "seconds elapsed: " << seconds_elapsed << endl;
    power += seconds_elapsed * current_score_map(current_score);
    // cout << "power: " << power << endl;
    if (input.size() > 3) {
        // cout << "input[3]: " << input[3] << endl;
        current_score += stoi(input[3]);
    }
    v_clock = parse_clock(input[1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n = 0;

    while (1) {

        string start_input;
        getline(cin, start_input);

        if (cin.eof())
            return 0;

        string start_clock = start_input.substr(6, 8);
        string home = start_clock; string guest = start_clock;

        vector<int> v_home = parse_clock(home); vector<int> v_guest = parse_clock(guest);
        int home_power = 0, guest_power = 0;

        int current_home_score = 0, current_guest_score = 0;


        while (1) {
            string next_input;
            getline(cin, next_input);

            vector<string> input = parse_score_or_end(next_input);

            if (input[0] == "END") {
                // insert terminating logic here;
                    increment_power(current_home_score, v_home, input, home_power);
                    increment_power(current_guest_score, v_guest, input, guest_power);
                break;
            } else {
                if (input[2] == "home") {
                    // cout << "home." << endl;
                    increment_power(current_home_score, v_home, input, home_power);
                } else {
                    // cout << "guest." << endl;
                    increment_power(current_guest_score, v_guest, input, guest_power);
                }
            }
        }

        cout << "Case " << ++n << ": " << home_power + guest_power << endl;
    }

    return 0;
}
