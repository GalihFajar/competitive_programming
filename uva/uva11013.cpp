#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef int fv(vi&);
typedef fv* pfv;

template<typename T>
void printVector(vector<T> v) {
    for (auto elem: v) {
        cout << elem << " ";
    }
}

bool is_straight(vi& in, int start_idx, int straight_size) {
    bool first = true;
    for (int i = start_idx; i < (int) in.size() && i < start_idx + straight_size; i++) {
        if (first) {
            first = false;
            continue;
        }

        if (!(in[i] - 1 == in[i - 1] || in[i] + 13 - 1 == in[i - 1]))
            return false;
    }

    return true;
}

int five_straight(vi& in) {
    if (is_straight(in, 0, 5)) {
        return 100;
    }

    return 0;
}

int four_straight(vi& in) {
    if (is_straight(in, 0, 4)) {
        return 10;
    }

    return 0;
}

int three_two_straight(vi& in) {
    if (is_straight(in, 0, 3) && is_straight(in, 3, 2)) {
        return 5;
    }

    return 0;
}

int three_straight(vi& in) {
    if (is_straight(in, 0, 3) && !is_straight(in, 3, 2)) {
        return 3;
    }

    return 0;
}

int two_two_straight(vi& in) {
    if (is_straight(in, 0, 2) && is_straight(in, 2, 2)) {
        return 1;
    }

    return 0;
}

int best_straight(vi& in) {
    vector<pfv> functions{&five_straight, &four_straight, &three_two_straight, &three_straight, &two_two_straight};

    for (int i = 0; i < (int) functions.size(); i++) {
        int temp = functions[i](in);
        if (temp != 0)
            return temp;
    }

    return 0;
}

void permute(vi& in, vi& current, vb& visited, int& max_point) {
    // prune the search
    if ((int) current.size() >= 2 && !is_straight(current, 0, 2)) {
        max_point = max(max_point, 0);
        return;
    }

    if (current.size() == in.size()) {
        max_point = max(max_point, best_straight(current));
    } else {
        for (int i = 0; i < (int) in.size(); i++) {
            if (visited[i]) continue;
            visited[i] = true;
            current.push_back(in[i]);
            permute(in, current, visited, max_point);

            visited[i] = false;
            current.pop_back();
        }
    }
}

void init_rem_cards(unordered_map<int, int>& rem_cards, vi& hand_cards) {
    for (int i = 1; i <= 13; i++) {
        rem_cards[i] = 4;
    }

    for (int i: hand_cards) {
        rem_cards[i]--;
    }
}

int convert(string& input) {
    char c = input[0];

    if (c == 'A')
        return 1;
    else if (c == 'T')
        return 10;
    else if (c == 'J')
        return 11;
    else if (c == 'Q')
        return 12;
    else if (c == 'K')
        return 13;

    return c - '0';
}

template <typename T>
void print_vector(vector<T> v) {
    for (auto elem: v) {
        cout << elem << " ";
    }
}

template <typename T, typename K>
void print_hash_map(unordered_map<T, K> um) {
    for (auto elem: um) {
        cout << '[' << elem.first << ' ' << elem.second << "]\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (1) {
        string j, k, l, m, n;
        cin >> j;
        if (j[0] == '#') return 0;
        cin >> k >> l >> m >> n;

        int a = convert(j), b = convert(k), c = convert(l), d = convert(m), e = convert(n);

        vi v{a, b, c, d, e};
        vector<string> vs{j, k, l, m, n};
        vector<float> expected_values;
        vi out;
        vector<bool> visited(5);
        unordered_map<int, int> rem_cards;
        init_rem_cards(rem_cards, v);
        // print_hash_map(rem_cards);
        // cout << '\n';

        int max_point = -1;
        permute(v, out, visited, max_point);

        // brute force all
        for (int i = 0; i < (int) v.size(); i++) {
        // for (int i = 3; i <= 3; i++) {
            int temp = v[i];
            float expected_value = 0;
            for (int card = 1; card <= 13; card++) {
                int local_max = -1;
                vector<int> current;
                v[i] = card;
                permute(v, current, visited, local_max);
                // cout << "selected_card: " << card << endl;
                // cout << "local_max: " << local_max << '\n' ;

                if (local_max > 0) {
                    float current_ex_value = local_max * ((float) rem_cards[card] / 47);
                    expected_value += current_ex_value;
                }
            }

            expected_values.push_back(expected_value - (float) 2);
            // cout << "expected_value: " << expected_value << '\n';
            v[i] = temp;
        }
        max_point -= 1;

        int selected_idx = -1;
        float current_max = (float) max_point;
        for (int i = 0; i < (int) expected_values.size(); i++) {
            if (expected_values[i] > current_max) {
                selected_idx = i;
                current_max = expected_values[i];
            }
        }

        // cout << "max_point: " << max_point << '\n';
        // print_vector(expected_values); cout << '\n';


        if (selected_idx == -1)
            cout << "Stay\n";
        else
            cout << "Exchange " << vs[selected_idx] << '\n';
    }

    return 0;
}
