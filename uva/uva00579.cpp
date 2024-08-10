#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
using namespace std;

const double hour_inc = 360/12.0;
const double hour_inc_from_min = 30/60.0;
const double min_inc = 360/60.0;

double calculate_hour(int h, int m) {
    return hour_inc * h + hour_inc_from_min * m;
}

double calculate_min(int m) {
    return m * min_inc;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (1) {
        string in;
        vector<string> hour_min;
        cin >> in;

        string temp = "";
        for (int i = 0; i < (int) in.size(); i++) {
            if (in[i] == ':') {
                hour_min.push_back(temp);
                temp = "";
                continue;
            }

            temp += in[i];
        }

        hour_min.push_back(temp);

        if (hour_min[0] == "0" && hour_min[1] == "00") return 0;

        int hour = stoi(hour_min[0]);
        int minute = stoi(hour_min[1]);

        double angle = abs(calculate_hour(hour, minute) - calculate_min(minute));
        if (angle > 180.0)
            angle = abs(angle - 360.0);
        cout << setprecision(3) << fixed;
        cout << angle << '\n';
    }

    return 0;
}
