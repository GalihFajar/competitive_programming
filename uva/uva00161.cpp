#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

template <typename T>
void print_vector_pair(vector<pair<T, T>>& vp) {
    cout << '[';
    for (auto p: vp) {
        cout << '(' << p.first << " " << p.second << ")";
    }
    cout << "]\n";
}

template <typename T>
void print_vector_tuple(vector<tuple<T, T, T>>& vp) {
    int start, end, inc;
    cout << '[';
    for (auto p: vp) {
        tie(start, end, inc) = p;
        cout << '(' << start << " " << end << " " << inc << ")";
    }
    cout << "]\n";
}


template<typename T>
bool sort_end_diff(tuple<T, T, T>& t1, tuple<T, T, T>& t2) {
    int _a, b, _c, _d, e, _f;
    tie(_a, b, _c) = t1;
    tie(_d, e, _f) = t2;

    return b < e;
}


bool slicing(pii& s1, pii& s2) {
    int start_1, end_1, start_2, end_2;
    tie(start_1, end_1) = s1;
    tie(start_2, end_2) = s2;


    return !(end_1 < start_2 || start_1 > end_2);
}

bool slicing_tuple(tiii& s1, tiii& s2) {
    int start_1, end_1, inc_1, start_2, end_2, inc_2;
    tie(start_1, end_1, inc_1) = s1;
    tie(start_2, end_2, inc_2) = s2;


    return !(end_1 < start_2 || start_1 > end_2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (1) {
        vector<int> inputs;
        vector<tiii> states;

        int input;

        while (cin >> input, input != 0) {
            inputs.push_back(input);
            states.push_back({0, input - 5 - 1, input});
        }
        if (states.empty()) return 0;

        sort(inputs.begin(), inputs.end());
        sort(states.begin(), states.end());

        // only use
        int earliest_yellow_end = inputs[0];

        while (1) {
            int smallest_start, smallest_end, smallest_inc;
            tie(smallest_start, smallest_end, smallest_inc) = states[0];


            if (smallest_start >= 5 * 3600 || smallest_start < 0) {
                cout << "Signals fail to synchronise in 5 hours\n";
                break;
            }

            bool all_slicing = true;
            for (int i = 0; i < states.size(); i++) {
                for (int j = 0; j < states.size(); j++) {
                    if (i == j) continue;
                    all_slicing &= slicing_tuple(states[i], states[j]);
                }
            }


            if (all_slicing) {
                int max_start = -1;
                for (int i = 0; i < (int) states.size(); i++) {
                    int a, b, c;
                    tie(a,b,c) = states[i];

                    max_start = max(max_start, a);
                }

                if (max_start > earliest_yellow_end) {
                    int out = max_start;
                    int hour = out / 3600;
                    int minutes = (out % 3600) / 60;
                    int seconds = (out % 60);

                    cout << setw(2) << setfill('0');
                    cout << hour << ":";
                    cout << setw(2) << setfill('0');
                    cout << minutes << ":";
                    cout << setw(2) << setfill('0');
                    cout << seconds << '\n';
                    break;

                }

            }

            // update the most late state
            int start, end, inc;
            tie(start, end, inc) = states[0];

            states[0] = {start + 2 * inc, end + 2 * inc, inc};

            sort(states.begin(), states.end(), sort_end_diff<int>);
        }
    }

    return 0;
}
