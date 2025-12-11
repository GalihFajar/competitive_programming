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

void press(string& s, vi& button_pressed) {
    for (auto& i: button_pressed) {
	if (i == '#')
	    s[i] = '.';
	else 
	    s[i] = '#';
    }
}

string press_return(string temp, vi& button_pressed) {
    string s = temp;
    for (auto& i: button_pressed) {
	cout << "i: " << i << "\n";
	if (s[i] == '#') {
	    s[i] = '.';
	}
	else if (s[i] == '.') {
	    s[i] = '#';
	}
    }

    return s;
}

int search(Machine* m, string indicator, int current_press, int prev) {
    if (is_all_same(indicator, '.') || current_press> 1000) 
	return current_press;

    cout << "prev: " << prev << endl;
    cout << "indicator:" << indicator << endl;

    int n = m->buttons.size();
    int min_press = INT_MAX;
    for (int i = 0; i < n; i++) {
	if (i == prev) {
	    continue;
	}

	string flipped = press_return(indicator, m->buttons[i]);

	min_press = min(min_press, search(m, flipped, current_press + 1, i));
    }

    return min_press;
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
    }
    ans += search(machines[0], machines[0]->indicator, 0, -1);

    // string indicator = ".##.";
    // vi asdf = {1, 3};
    // cout << press_return(indicator, asdf) << endl;


    cout << ans << endl;
    

    return 0;
}


/*
 *
 *
*/
