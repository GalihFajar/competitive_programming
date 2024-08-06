#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool is_number(char c) {
    return (c - '0') >= 0 && (c - '0') <= 9;
}

int parse_input(string& input) {
    if (input[1] == 'x') {
    // convert hex
        int out = 0;
        int power = 0;

        for (int i = (int) input.size() - 1; i >= 2; i--) {
            char c = input[i];
            int num;
            if (is_number(c)) {
                num = c - '0';
            } else {
                num = c - 'A' + 10;
            }
            out += num * pow(16, power++);
        }

        return out;
    } else if (input[0] == '0') {
    // convert octal
        int out = 0;
        int power = 0;

        for (int i = (int) input.size() - 1; i >= 0; i--) {
            char c = input[i];
            int num = c - '0';
            out += num * pow(8, power++);
        }

        return out;
    }

    return stoi(input);
}

int do_op(int& input, string& op) {
    int temp = input;
    if (op == "++i") {
        ++input;
        return input;
    } else if (op == "i++") {
        input++;
        return temp;
    } else if (op == "--i") {
        --input;
        return input;
    } else if (op == "i--") {
        input--;
        return temp;
    }

    return input;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (1) {
        string input;
        int ops;
        int score = 0;
        cin >> input >> ops;
        if (ops == 0) return 0;
        int asdf = 100;
        string temp_op = "--i";
        string temp_asdf = "0777";
        // cout << "temp_asdf: " << parse_input(temp_asdf) << endl;
        // cout << "asdf: " << do_op(asdf, temp_op) << endl;


        int parsed_input = parse_input(input);

        vector<int> results;

        while (ops--) {
            string op;
            int written;

            cin >> op >> written;
            int expected = parsed_input;
            expected = do_op(parsed_input, op);
            // printf("written: %d, expected: %d\n", written ,expected);

            if (written == expected) {
                score++;
            } else {
                parsed_input = written;
                if (op == "i++" || op == "i--") {
                    do_op(parsed_input, op);
                }
                // do_op(parsed_input, op);
            }
        }

        cout << score << '\n';
    }

    return 0;
}
