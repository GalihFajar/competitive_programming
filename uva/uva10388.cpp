#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;

void printVector(vector<char>& vec) {
    for (auto c: vec) {
        cout << c;
    }
}

void printVectorReverse(vector<char>& vec) {
    for (int i = (int) vec.size() - 1; i >= 0; i--) {
        cout << vec[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int tc;
    cin >> tc;

    while (tc--) {
        // int blank;
        // cin >> blank;

        // initializing
        string jane, john;
        vector<char> jane_up, jane_down, john_up, john_down;

        cin >> jane >> john;

        for (int i = (int) jane.size() - 1; i >= 0; i--) {
            jane_down.push_back(jane[i]);
            john_down.push_back(john[i]);
        }

        int totalSize = (int) jane.size() + (int) john.size();
        // cout << "totalSize: " << totalSize << '\n';

        int turns = 1000;

        while (turns--) {
            char jane_card, john_card;
            jane_card = jane_down.back(); jane_down.pop_back(); jane_up.push_back(jane_card);
            john_card = john_down.back(); john_down.pop_back(); john_up.push_back(john_card);

            if (john_card == jane_card) {
                // john snap
                int rand = random() / 141 % 2;

                // jane snaps first
                if (rand == 0) {
                    jane_up.insert(jane_up.end(), john_up.begin(), john_up.end());
                    john_up.clear();

                    cout << "Snap! for Jane: ";
                    printVectorReverse(jane_up);
                    cout << '\n';
                // john snaps first
                } else {
                    john_up.insert(john_up.end(), jane_up.begin(), jane_up.end());
                    jane_up.clear();

                    cout << "Snap! for John: ";
                    printVectorReverse(john_up);
                    cout << '\n';
                }
            }

            // cout << "Jane up: ";
            // printVector(jane_up);
            // cout << '\n';
            // cout << "Jane down: ";
            // printVector(jane_down);
            // cout << '\n';
            // cout << "John up: ";
            // printVector(john_up);
            // cout << '\n';
            // cout << "John down: ";
            // printVector(john_down);
            // cout << '\n';

            // cout << "john total size: " << (int) john_down.size() + (int) john_up.size() << '\n';
            // cout << "jane total size: " << (int) jane_down.size() + (int) jane_up.size() << '\n';

            if (((int) john_down.size() + (int) john_up.size()) == totalSize) {
                cout << "John wins." << '\n';
                break;
            } else if (((int) jane_down.size() + (int) jane_up.size()) == totalSize) {
                cout << "Jane wins." << '\n';
                break;
            }

            if (jane_down.empty()) {
                jane_down = jane_up;
                reverse(jane_down.begin(), jane_down.end());
                jane_up.clear();
            }

            if (john_down.empty()) {
                john_down = john_up;
                reverse(john_down.begin(), john_down.end());
                john_up.clear();
            }
        }
        if (turns == 0)
            cout << "Keeps going and going ...\n";
        if (tc != 0)
            cout << '\n';
    }

    return 0;
}


// ADCBA -> adcba
    // _ -> abcb
// CDABC -> cdab
    // _ -> _
