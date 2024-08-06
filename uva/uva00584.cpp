#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (1) {
        string input;
        string cleaned_input;
        getline(cin, input);

        if (input == "Game Over") return 0;
        for (int i = 0; i < (int) input.size(); i++) {
            if (input[i] == ' ') continue;
            cleaned_input += input[i];
        }
        // cout << "input: " << cleaned_input << endl;

        int out = 0;
        int processed_roll = 0;
        int last_processed = 0;

        for (int i = 0; i < (int) cleaned_input.size() && processed_roll < 20; i++) {
            char c = cleaned_input[i];
            if (c != '/' && c != 'X') {
                out += c - '0';
                processed_roll++;
            } else if (c == '/') {
                char next = cleaned_input[i + 1];
                out += 10;
                out -= (cleaned_input[i - 1] - '0');
                if (next == 'X') {
                    out += 10;
                } else {
                    out += (next - '0');
                }
                processed_roll++;
            } else if  (c == 'X') {
                char next = cleaned_input[i + 1];
                out += 10;
                if (next == 'X') {
                    out += 10;
                } else {
                    out += (next - '0');
                }

                if (i + 2 < (int) cleaned_input.size()) {
                    char next_next = cleaned_input[i + 2];
                    if (next_next == 'X') {
                        out += 10;
                    } else if (next_next == '/') {
                        out -= (next - '0');
                        out += 10;
                    } else {
                        out += (next_next - '0');
                    }
                }

                processed_roll += 2;
            }
            // cout << "out: " << out << endl;

            last_processed = i;
        }


        // cout << "last processed: " << cleaned_input[last_processed] << " ," << last_processed << '\n';
        // last_processed++;
        // cout << "current out: " << out << '\n';

        // if (cleaned_input[last_processed] == 'X') {
        //     cout << "mashok 1" << endl;
        //     out += 10;
        //     char next = cleaned_input[last_processed + 1];
        //     char next_next = cleaned_input[last_processed + 2];
        //     if (next == 'X') {
        //         out += 10;
        //     } else {
        //         out += (next - '0');
        //     }
        //     if (next_next == 'X') {
        //         out += 10;
        //     } else if (next_next == '/') {
        //         out -= next - '0';
        //         out += 10;
        //     } else {
        //         out += (next - '0');
        //     }

        // } else {
        //     out += cleaned_input[last_processed] - '0';
        //     last_processed++;


        // }

        cout << out << '\n';
    }

    return 0;
}

/*
0 1 2 3 4 5 6 7 8 9 10 11
[10 + (1)][10 + (2)][10 + (3)][10 + (4)][10 + (5)][10 + (6)][10 + (7)][10 + (8)][10 + (9)][10 + (10)][10]
[110][100][90][80][70][60][50][40][30][20][10]


1 + / + 4 + X + 6 + x + / + / + X + 1 + 2
2 1 (10 + 1 + 2) (20 + 1 + 2) (10 + 3) (10 + 1) (10 + 24) (6) (10 + 30 + 10) + 4 + 14 + 1

*/
