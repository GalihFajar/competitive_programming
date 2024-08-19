#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
using namespace std;

unordered_map<string, float> timezones {
    {"UTC", 0},
    {"GMT", 0},
    {"WET", 0},
    {"BST", 1},
    {"IST", 1},
    {"WEST", 1},
    {"CET", 1},
    {"CEST", 2},
    {"EET", 2},
    {"EEST", 3},
    {"MSK", 3},
    {"MSD", 4},
    {"AST", -4},
    {"ADT", -3},
    {"NST", -3.5},
    {"NDT", -2.5},
    {"EST", -5},
    {"EDT", -4},
    {"CST", -6},
    {"CDT", -5},
    {"MST", -7},
    {"MDT", -6},
    {"PST", -8},
    {"PDT", -7},
    {"HST", -10},
    {"AKST", -9},
    {"AKDT", -8},
    {"AEST", 10},
    {"AEDT", 11},
    {"ACST", 9.5},
    {"ACDT", 10.5},
    {"AWST", 8}
};

pair<string, string> resolve_noon_mid(string& s) {
    if (s == "noon") {
        return {"12:00", "p.m."};
    } else if (s == "midnight") {
        return {"12:00", "a.m."};
    }

    return {};
}

pair<string, string> parse_time(string& s) {
    string out = "";
    pair<string, string> out_p;

    for (char c: s) {
        if (c == ':') {
            out_p.first = out;
            out = "";
            continue;
        }

        out += c;
    }

    out_p.second = out;

    return out_p;
}

void toggle_time_period(string& s) {
    if (s == "p.m.")
        s = "a.m.";
    else
        s = "p.m.";
}

string resolve_hour(string hour, string& tz) {
    if ((hour != "12" && tz == "p.m.") || (hour == "12" && tz == "a.m.")) {
        return to_string(stoi(hour) + 12);
    }

    return hour;
}

pair<double, double> resolve_timezone(string& time_zone) {

    double hour = floor(abs(timezones[time_zone]));
    double minute = abs(timezones[time_zone]) - hour;

    if (timezones[time_zone] < 0) {
        hour = -hour;
        minute = -minute;
    }

    return {hour, minute};
}

int pos_mod(int n, int m) {
    return ((n % m) + m) % m;
}

pair<double, double> parse_hour_minute(double timezone) {
    double hour = floor(abs(timezone));
    double minute = abs(timezone) - hour;

    if (timezone < 0) {
        hour = -hour;
        minute = -minute;
    }

    return {hour, minute};
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        string time, time_period, zone_1, zone_2;
        bool midnight_or_noon = false;

        cin >> time;

        if (time != "noon" && time != "midnight") {
            cin >> time_period;
        } else {
            midnight_or_noon = true;
            tie(time, time_period) = resolve_noon_mid(time);
        }

        cin >> zone_1 >> zone_2;

        string hour, minute;
        tie(hour, minute) = parse_time(time);


        double zone_1_h, zone_1_m;
        double zone_2_h, zone_2_m;

        tie(zone_1_h, zone_1_m) = resolve_timezone(zone_1);
        tie(zone_2_h, zone_2_m) = resolve_timezone(zone_2);

        double temp_1 = timezones[zone_1];
        double temp_2 = timezones[zone_2];

        if (temp_2 > temp_1)
            swap(temp_1, temp_2);

        pair<double, double> pair_h_m = parse_hour_minute(temp_1 - temp_2);
        double diff_hour = pair_h_m.first;
        double diff_minute = pair_h_m.second;

        if (zone_1_h > zone_2_h ) {
            diff_hour *= -1;
            diff_minute *= -1;
        }

        diff_minute = diff_minute * 60;

        int resulting_hour = stoi(resolve_hour(hour, time_period)) + diff_hour;
        int resulting_min = stoi(minute) + diff_minute;

        if (resulting_min >= 60) {
            resulting_min = resulting_min - 60;
            resulting_hour += 1;
        } else if (resulting_min < 0) {
            resulting_min = 60 + resulting_min;
            resulting_hour -= 1;
        }

        resulting_hour = resulting_hour > 24 || resulting_hour < 0 ? pos_mod(resulting_hour, 24) : resulting_hour;
        if (resulting_hour == 0)
            resulting_hour = 24;

        if (resulting_hour == 12) {
            time_period = "p.m.";
        } else if (resulting_hour == 24) {
            resulting_hour = 12;
            time_period = "a.m.";
        } else if (resulting_hour > 12) {
            resulting_hour -= 12;
            time_period = "p.m.";
        } else if (resulting_hour < 12) {
            time_period = "a.m.";
        }

        if (resulting_hour == 12 && resulting_min == 0) {
            if (time_period == "a.m.")
                cout << "midnight\n";
            else
                cout << "noon\n";
        } else {
            cout << resulting_hour << ":";
            cout << setfill('0') << setw(2) << resulting_min << " " << time_period << '\n';
        }
    }

    return 0;
}
