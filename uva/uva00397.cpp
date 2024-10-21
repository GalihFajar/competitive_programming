#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <list>
using namespace std;

list<string> parse_to_ll(string& s) {

    string temp = "";
    list<string> l;
    bool last_op = false;
    bool first = true;

    for (int i = 0; i <= (int) s.size(); i++) {
        if (first) {
            first = false;
            if (s[i] == '+') continue;
            else if (s[i] == '-') {
                temp += s[i];
                continue;
            }
        }

        if ((s[i] <= '9' && s[i] >= '0') ||
        s[i] >= 'a' && s[i] <= 'z') {
            temp += s[i];
        } else {
            if (!temp.empty()) {
                if ((int) temp.size() > 1 && (temp[0] == '+')) {
                    temp = temp.substr(1, (int) temp.size() - 1);
                }

                l.push_back(temp);
                temp = "";
                last_op = false;
            }

            if (s[i] == '\0') continue;

            if (s[i] != ' ') {
                if (!last_op) {
                    string tmp = "";
                    tmp += s[i];
                    l.push_back(tmp);
                    last_op = true;

                    temp = "";
                } else {
                    last_op = false;
                    temp += s[i];
                }
            }
        }
    }

    return l;
}

void print_ll(list<string>& l) {
    for (auto it = l.begin(); it != l.end(); it++) {
        cout << *it;
        if (next(it) != l.end())
            cout << " ";
    }

    cout << "\n";
}

list<string>::iterator get_next_op(list<string>& l) {
    string next_op = "";
    list<string>::iterator next_op_it;

    for (auto it = l.begin(); it != l.end(); it++) {
        string op = *it;

        if (op == "+" || op == "-" || op == "*" || op == "/" || op == "=") {
            if (next_op.empty()) {
                next_op = op;
                next_op_it = it;
                continue;
            }

            if (op == "*" || op == "/") {
                if (next_op == "+" || next_op == "-") {
                    next_op_it = it;
                    next_op = op;
                }
            }
        }
    }

    return next_op_it;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    bool first = true;


    while (1) {
        string s; getline(cin, s); if (cin.eof()) return 0;

        if (!first)
            cout << '\n';
        else
            first = false;

        auto l = parse_to_ll(s);
        print_ll(l);

        while (1) {
                auto op_it = get_next_op(l);
                auto temp_op_it = op_it;


                if (*op_it == "=") {
                    break;
                }

                int x = [=] () -> int {
                    auto prev_it = prev(op_it);
                    auto next_it = next(op_it);
                    int a = stoi(*prev_it); int b = stoi(*next_it);

                    if (*op_it == "*") {
                        return a * b;
                    } else if (*op_it == "/") {
                        return a / b;
                    } else if (*op_it == "+") {
                        return a + b;
                    } else if (*op_it == "-") {
                        return a - b;
                    }

                    return -1;
                } ();

                op_it = l.erase(op_it);
                op_it = l.erase(op_it);
                op_it = prev(op_it);
                *op_it = to_string(x);

                print_ll(l);
            }
        }

    return 0;
}
