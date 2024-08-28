#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
#include <sstream>
using namespace std;

#define round_2 cout << setw(2) << setfill('0')

typedef vector<int> vi;

string int_to_string_with_leading(int number) {
    ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << number;
    return oss.str();
}

vi MONTH_31 = {1, 3, 5, 7, 8, 10, 12};
vector<pair<string, pair<int, int>>> ZODIACS = {
    {"aquarius", {121, 219}},
    {"pisces", {220, 320}},
    {"aries", {321, 420}},
    {"taurus", {421, 521}},
    {"gemini", {522, 621}},
    {"cancer", {622, 722}},
    {"leo", {723, 821}},
    {"virgo", {822, 923}},
    {"libra", {924, 1023}},
    {"scorpio", {1024, 1122}},
    {"sagittarius", {1123, 1222}},
    {"capricorn", {1223, 1320}},
};

void parse_date(string& in, vector<int>& out) {

    out.push_back(stoi(in.substr(0, 2)));
    out.push_back(stoi(in.substr(2, 2)));
    out.push_back(stoi(in.substr(4, 4)));
}

int month_date_limit(int m,int y) {
    if (m == 2) {
        if (y % 4 == 0) {
            if (y % 100 == 0) {
                if (y % 400 == 0)
                    return 29;
                else
                    return 28;
            }
            return 29;
        } else {
            return 28;
        }
    }

    for (auto max_mo: MONTH_31)
        if (max_mo == m)
            return 31;

    return 30;
}

void increment_40_weeks(vi& mm_dd_yy) {
    int mm = mm_dd_yy[0], dd = mm_dd_yy[1], yy = mm_dd_yy[2];

    int added_days = dd + 40 * 7;
    int max_days = month_date_limit(mm, yy);

    while (added_days > max_days) {
        added_days -= max_days;
        mm++;

        if (mm >= 13) {
            mm -= 12;
            yy++;
        }

        max_days = month_date_limit(mm, yy);
    }

    dd = added_days;

    mm_dd_yy[0] = mm;
    mm_dd_yy[1] = dd;
    mm_dd_yy[2] = yy;
}

string get_zodiac(vi& mm_dd_yy) {
    string temp = int_to_string_with_leading(mm_dd_yy[0]) + int_to_string_with_leading(mm_dd_yy[1]);
    int mm_dd = stoi(temp);

    if (mm_dd < 121) {
        mm_dd = mm_dd - 100 + 1300;
    }

    for (auto zodiac: ZODIACS) {
        if (mm_dd >= zodiac.second.first && mm_dd <= zodiac.second.second)
            return zodiac.first;
    }

    return "undefined";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    int cnt = 1;

    while (tc--) {
        vector<int> mm_dd_yy;
        string in; cin >> in;
        if (cin.eof()) return 0;
        parse_date(in, mm_dd_yy);
        increment_40_weeks(mm_dd_yy);

        cout << cnt++ << " ";
        round_2;
        cout << mm_dd_yy[0] << "/";
        round_2;
        cout << mm_dd_yy[1] << "/";
        round_2;
        cout << mm_dd_yy[2] << " " << get_zodiac(mm_dd_yy) << endl;
    }

    return 0;
}
