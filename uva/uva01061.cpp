#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef pair<string, char> psc;

template <typename K, typename T>
void print_vector_pair(vector<pair<K, T>>& v) {
    cout << '{';
    for (auto elem: v) {
        cout << "[" << elem.first << " " << elem.second << "] ";
    }
    cout << "}\n";
}

template <typename K, typename T>
void print_pair(pair<K, T>& p) {
    cout << "[" << p.first << " " << p.second << "]";
}

pair<string, char> blood_str_to_pair(string& a) {
    string a_temp, b_temp;
    if (a.size() > 2) {
        a_temp += a[0];
        a_temp += a[1];
        return {a_temp, a[2]};
    }

    a_temp += a[0];
    return {a_temp, a[1]};
}

pair<string, char> combination_to_blood_type(pair<string, char>& c_1, pair<string, char>& c_2) {
    string a_1 = c_1.first;
    char r_1 = c_1.second;
    string a_2 = c_2.first;
    char r_2 = c_2.second;

    unordered_map<string, string> blood_types {
        {"AA", "A"},
        {"AO", "A"},
        {"BB", "B"},
        {"BO", "B"},
        {"AB", "AB"},
        {"OO", "O"}
    };

    string bt = a_1 + a_2;
    sort(bt.begin(), bt.end());

    bt = blood_types[bt];
    char rs = '+';

    if (r_1 == '-' && r_2 == '-') {
        rs = '-';
    }

    return {bt, rs};
}

string combination_to_blood_type_str(pair<string, char>& c_1, pair<string, char>& c_2) {
    string bt; char rs;

    tie(bt, rs) = combination_to_blood_type(c_1, c_2);

    return bt + rs;
}

vector<pair<string, char>> blood_type_to_alleles(pair<string, char>& btr) {
    string bt = btr.first;
    char rs = btr.second;

    unordered_map<string, vector<string>> bta_map {
        {"A", {"A", "O"}},
        {"B", {"B", "O"}},
        {"AB", {"A", "B"}},
        {"O", {"O", "O"}}
    };

    vector<string> alleles = bta_map[bt];
    vector<pair<string, char>> out;

    if (rs == '-') {
        for (auto a: alleles) {
            out.push_back({a, '-'});
        }

        return out;
    }

    for (auto a: alleles) {
        out.push_back({a, '-'});
        out.push_back({a, '+'});
    }

    return out;
}

unordered_set<string> alleles_combinations(vector<pair<string, char>>& p1, vector<pair<string, char>>& p2) {
    unordered_set<string> blood_types;

    for (auto x: p1) {
        for (auto y: p2) {
            auto result = combination_to_blood_type_str(x, y);
            blood_types.insert(combination_to_blood_type_str(x, y));
        }
    }

    return blood_types;
}


string child_combination(string& a, string& b) {
    pair<string, char> a_pair = blood_str_to_pair(a);
    pair<string, char> b_pair = blood_str_to_pair(b);

    vector<pair<string, char>> a_alleles = blood_type_to_alleles(a_pair);
    vector<pair<string, char>> b_alleles = blood_type_to_alleles(b_pair);

    unordered_set<string> blood_types = alleles_combinations(a_alleles, b_alleles);
    vector<string> temp;

    for (auto iter = blood_types.begin(); iter != blood_types.end(); ++iter) {
        temp.push_back(*iter);
    }

    if (temp.size() == 1)
        return temp[0];

    string out = "{";

    for (int i = 0; i < (int) temp.size(); i++) {
        if (i == 0)
            out += temp[i];
        else {
            out += ", ";
            out += temp[i];
        }
    }
    out += '}';

    return out;
}


string possible_parent(string& parent_1, string& child) {
    vector<string> blood_types {"A", "B", "AB", "O"};
    vector<char> rh {'+', '-'};

    pair<string, char> parent_1_pair = blood_str_to_pair(parent_1);
    vector<pair<string, char>> parent_1_alleles =  blood_type_to_alleles(parent_1_pair);

    vector<string> parent_2_possibilities;

    for (int i = 0; i < (int) blood_types.size(); i++) {
        for (int j = 0; j < (int) rh.size(); j++) {
            string possible_blood_type = "";
            possible_blood_type += blood_types[i];
            possible_blood_type += rh[j];

            pair<string, char> possible_parent_pair = blood_str_to_pair(possible_blood_type);
            vector<pair<string, char>> possible_parent_alleles = blood_type_to_alleles(possible_parent_pair);

            unordered_set<string> possible_child = alleles_combinations(parent_1_alleles, possible_parent_alleles);

            if (possible_child.find(child) != possible_child.end())
                parent_2_possibilities.push_back(possible_blood_type);
        }
    }

    if (parent_2_possibilities.empty())
        return "IMPOSSIBLE";
    if (parent_2_possibilities.size() == 1) {
        return parent_2_possibilities[0];
    }

    string out = "{";
    for (int i = 0; i < (int) parent_2_possibilities.size(); i++) {
        if (i == 0)
            out += parent_2_possibilities[i];
        else {
            out += ", ";
            out += parent_2_possibilities[i];
        }
    }
    out += "}";

    return out;
}

void print_possible_parent(string& parent_1, string& child) {
    vector<string> blood_types {"A", "B", "AB", "O"};
    vector<char> rh {'+', '-'};

    pair<string, char> parent_1_pair = blood_str_to_pair(parent_1);
    vector<pair<string, char>> parent_1_alleles =  blood_type_to_alleles(parent_1_pair);

    vector<string> parent_2_possibilities;

    for (int i = 0; i < (int) blood_types.size(); i++) {
        for (int j = 0; j < (int) rh.size(); j++) {
            string possible_blood_type = "";
            possible_blood_type += blood_types[i];
            possible_blood_type += rh[j];

            pair<string, char> possible_parent_pair = blood_str_to_pair(possible_blood_type);
            vector<pair<string, char>> possible_parent_alleles = blood_type_to_alleles(possible_parent_pair);

            unordered_set<string> possible_child = alleles_combinations(parent_1_alleles, possible_parent_alleles);

            if (possible_child.find(child) != possible_child.end())
                parent_2_possibilities.push_back(possible_blood_type);
        }
    }


    if (parent_2_possibilities.empty())
        cout << "IMPOSSIBLE";
    else {
        cout << '{';
        for (int i = 0; i < (int) parent_2_possibilities.size(); i++) {
            if (i == 0)
                cout << parent_2_possibilities[i];
            else
                cout << ", " << parent_2_possibilities[i];
        }
        cout << "}";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n = 1;
    while (1) {
        string a, b, c;

        cin >> a >> b >> c;

        if (a == "E" && b == "N" && c == "D") return 0;
        cout << "Case " << n << ": ";
        n++;

        if (a == "?") {
            cout << possible_parent(b, c);
        } else
            cout << a;

        cout << " ";


        if (b == "?") {
            cout << possible_parent(a, c);
        } else
            cout << b;

        cout << " ";

        if (c == "?") {

            cout << child_combination(a, b);
        } else
            cout << c;

        cout << '\n';
    }


    return 0;
}
