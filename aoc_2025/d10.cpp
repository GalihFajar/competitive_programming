#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <sstream>
using namespace std;

template <typename T> using v = vector<T>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vs = v<string>;

#define all(x) begin(x), end(x)
#define fio(name) freopen(name ".in", "r", stdin); freopen(name ".out", "w", stdout);
#define psp(x) cout << x << " ";
#define pnl(x) cout << x << "\n";

template <typename T>
void print_v(vector<T>& v) {
    for (auto const& elem: v) {
	cout << elem << " ";
    }
    cout << endl;
}

typedef struct Machine {
    string indicator;
    vvi buttons;
    vi joltage;
} Machine;


Machine* parse(string input) {
    vs input_string;
    stringstream ss(input);
    string t;
    Machine* out = new Machine;

    while (getline(ss, t, ' ')) 
	input_string.push_back(t);

    for (int i = 0; i < input_string.size(); i++) {
	for (auto& c: input_string[i]) {
	    if (c == '[' || c == ']' || c == '{' || c == '}' || c == '(' || c == ')')
		c = ' ';
	}

	if (i == 0) {
	    string temp = "";
	    for (auto& c: input_string[i]) {
		if (c == '.' || c == '#')
		    temp += c;
	    }
	    out->indicator = temp;
	} else if (i == input_string.size() - 1) {
	    stringstream ss_temp(input_string[i]);
	    string temp;
	    vi v;
	    while (getline(ss_temp, temp, ','))
		v.push_back(stoi(temp));
	    out->joltage = v;
	} else {
	    stringstream ss_temp(input_string[i]);
	    string temp;
	    vi v;
	    while (getline(ss_temp, temp, ','))
		v.push_back(stoi(temp));
	    out->buttons.push_back(v);
	}
    }

    return out;
}

void print_machine(Machine* m) {
    cout << "indicator: " << m->indicator << endl;
    cout << "buttons: \n";
    for (vi& b: m->buttons) {
	cout << "\t";
	print_v(b);
    }
    cout << "joltage: ";
    print_v(m->joltage);
    cout << endl;
}

bool is_all_same(string& s, char target) {
    for (auto const& c: s)
	if (c != target)
	    return false;

    return true;
}

string press_return(string temp, vi& button_pressed) {
    string s = temp;
    for (auto& i: button_pressed) {
	if (s[i] == '#') {
	    s[i] = '.';
	}
	else if (s[i] == '.') {
	    s[i] = '#';
	}
    }

    return s;
}

unordered_map<string, int> dp;

// using subset approach
int solve(Machine* m, string current_lights, int idx) {
    if (idx == m->buttons.size()) {
	if (is_all_same(current_lights, '.')) 
	    return 0;
	return 1e9;
    }

    string key = current_lights + '$' + to_string(idx);
    if (dp.count(key)) return dp[key];

    int cost_skip = solve(m, current_lights, idx + 1);
    string flipped = press_return(current_lights, m->buttons[idx]);
    int cost_choose = 1 + solve(m, flipped, idx + 1);

    dp[key] = min(cost_skip, cost_choose);

    return dp[key];
}

int search(Machine* m, string indicator, int current_press, int current_idx) {
    string param = indicator;
    param += '$';
    param += to_string(current_idx);

    if (dp[param]) {
	return dp[param];
    }

    dp[param] = INT_MAX;
    string flipped = press_return(indicator, m->buttons[current_idx]);
    if (is_all_same(flipped, '.'))  {
	return current_press;
    }

    int n = m->buttons.size();
    int min_press = INT_MAX;
    for (int i = 0; i < n; i++) {
	if (i == current_idx) {
	    continue;
	}


	min_press = min(min_press, search(m, flipped, current_press + 1, i));
    }
    dp[param] = min(dp[param], min_press);

    return dp[param];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fio("<filename_prefix>")
    v<Machine*> machines;


    string s;
    while (getline(cin, s)) {
	machines.push_back(parse(s));
    }

    int n = machines.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
	Machine* m = machines[i];
	dp.clear();

	int result = solve(m, m->indicator, 0);
	ans += result;
    }


    cout << ans << endl;
    

    return 0;
}


/*
 *
 *
*/
