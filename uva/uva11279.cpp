#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
using namespace std;

unordered_map<char, pair<char, char>> qwerty_map {
    {'`', {0, 0}},
    {'~', {0, 0}},
    {'1', {0, 1}},
    {'!', {0, 1}},
    {'2', {0, 2}},
    {'@', {0, 2}},
    {'3', {0, 3}},
    {'#', {0, 3}},
    {'4', {0, 4}},
    {'$', {0, 4}},
    {'5', {0, 5}},
    {'%', {0, 5}},
    {'6', {0, 6}},
    {'^', {0, 6}},
    {'7', {0, 7}},
    {'&', {0, 7}},
    {'8', {0, 8}},
    {'*', {0, 8}},
    {'9', {0, 9}},
    {'(', {0, 9}},
    {'0', {0, 10}},
    {')', {0, 10}},
    {'-', {0, 11}},
    {'_', {0, 11}},
    {'=', {0, 12}},
    {'+', {0, 12}},

    {'q', {1, 1}},
    {'w', {1, 2}},
    {'e', {1, 3}},
    {'r', {1, 4}},
    {'t', {1, 5}},
    {'y', {1, 6}},
    {'u', {1, 7}},
    {'i', {1, 8}},
    {'o', {1, 9}},
    {'p', {1, 10}},
    {'[', {1, 11}},
    {'{', {1, 11}},
    {']', {1, 12}},
    {'}', {1, 12}},
    {'\\', {1, 13}},
    {'|', {1, 13}},

    {'a', {2, 1}},
    {'s', {2, 2}},
    {'d', {2, 3}},
    {'f', {2, 4}},
    {'g', {2, 5}},
    {'h', {2, 6}},
    {'j', {2, 7}},
    {'k', {2, 8}},
    {'l', {2, 9}},
    {';', {2, 10}},
    {':', {2, 10}},
    {'\'', {2, 11}},
    {'"', {2, 11}},

    {'z', {3, 1}},
    {'x', {3, 2}},
    {'c', {3, 3}},
    {'v', {3, 4}},
    {'b', {3, 5}},
    {'n', {3, 6}},
    {'m', {3, 7}},
    {',', {3, 8}},
    {'<', {3, 8}},
    {'.', {3, 9}},
    {'>', {3, 9}},
    {'/', {3, 10}},
    {'?', {3, 10}}
};
unordered_map<char, pair<char, char>> dvorak_map {
    {'`', {0, 0}},
    {'~', {0, 0}},
    {'1', {0, 1}},
    {'!', {0, 1}},
    {'2', {0, 2}},
    {'@', {0, 2}},
    {'3', {0, 3}},
    {'#', {0, 3}},
    {'q', {0, 4}},
    {'j', {0, 5}},
    {'l', {0, 6}},
    {'m', {0, 7}},
    {'f', {0, 8}},
    {'p', {0, 9}},
    {'/', {0, 10}},
    {'?', {0, 10}},
    {'[', {0, 11}},
    {'{', {0, 11}},
    {']', {0, 12}},
    {'}', {0, 12}},

    {'4', {1, 1}},
    {'$', {1, 1}},
    {'5', {1, 2}},
    {'%', {1, 2}},
    {'6', {1, 3}},
    {'^', {1, 3}},
    {'.', {1, 4}},
    {'>', {1, 4}},
    {'o', {1, 5}},
    {'r', {1, 6}},
    {'s', {1, 7}},
    {'u', {1, 8}},
    {'y', {1, 9}},
    {'b', {1, 10}},
    {';', {1, 11}},
    {':', {1, 11}},
    {'=', {1, 12}},
    {'+', {1, 12}},
    {'\\', {1, 13}},
    {'|', {1, 13}},

    {'7', {2, 1}},
    {'&', {2, 1}},
    {'8', {2, 2}},
    {'*', {2, 2}},
    {'9', {2, 3}},
    {'(', {2, 3}},
    {'a', {2, 4}},
    {'e', {2, 5}},
    {'h', {2, 6}},
    {'t', {2, 7}},
    {'d', {2, 8}},
    {'c', {2, 9}},
    {'k', {2, 10}},
    {'-', {2, 11}},
    {'_', {2, 11}},

    {'0', {3, 1}},
    {')', {3, 1}},
    {'z', {3, 2}},
    {'x', {3, 3}},
    {',', {3, 4}},
    {'<', {3, 4}},
    {'i', {3, 5}},
    {'n', {3, 6}},
    {'w', {3, 7}},
    {'v', {3, 8}},
    {'g', {3, 9}},
    {'\'', {3, 10}},
    {'"', {3, 10}}
};

// vector<char> two_handed_qwerty {'a', 's', 'd', 'f', 'j', 'k', 'l'};
string two_handed_qwerty_s = "asdfjkl;";
// vector<char> one_handed_qwerty {'f', 'g', 'h', 'j'};
string one_handed_qwerty_s = "fghj";
// vector<char> dvorak {'e', 'h', 't', 'd'};
string dvorak_s = "ehtd";

double euclidean(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double euclidean_pair(pair<int, int> p1, pair<int, int> p2) {
    double x1, x2, y1, y2;
    tie(x1, y1) = p1; tie(x2, y2) = p2;

    return euclidean(x1, y1, x2, y2);
}

tuple<double, double, double> calculate(string& s) {
    double two_handed_qwerty = 0, one_handed_qwerty = 0, dvorak = 0;

    for (char c: s) {
        if (c == ' ')
            continue;
        c = tolower(c);

        // calculate two_handed
        double temp_min = 999999;
        for (char thq_c: two_handed_qwerty_s) {
            temp_min = min(temp_min, euclidean_pair(qwerty_map[thq_c], qwerty_map[c]));
        }

        two_handed_qwerty += temp_min * 2;

        // calculate one_handed
        temp_min = 999999;
        for (char ohq_c: one_handed_qwerty_s) {
            temp_min = min(temp_min, euclidean_pair(qwerty_map[ohq_c], qwerty_map[c]));
        }

        one_handed_qwerty += temp_min * 2;

        // calculate dvorak
        temp_min = 999999;
        for (char dv_c: dvorak_s) {
            temp_min = min(temp_min, euclidean_pair(dvorak_map[dv_c], dvorak_map[c]));
        }

        dvorak += temp_min * 2;
    }

    return {two_handed_qwerty, one_handed_qwerty, dvorak};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    while (1) {
        string s;
        getline(cin, s);

        if (cin.eof())
            break;

        double a, b, c;
        tie(a, b, c) = calculate(s);

        cout << setprecision(2) << fixed;
        cout << a << " " << b << " " << c << '\n';
    }

    return 0;
}
