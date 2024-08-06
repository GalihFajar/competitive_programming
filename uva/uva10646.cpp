#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
using namespace std;


int cardValue(string card) {
    // return 0;
    char front = card[0];
    int value = front - '0';

    if (value >= 0 && value <= 9) {
        return value;
    }

    return 10;
}

void printVector(vector<string> v) {
    cout << "[ ";
    for (auto s: v) {
        cout << s << " ";
    }
    cout << "]\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    int n = 0;

    while (tc--) {
        ++n;
        int totalCard = 52;
        string inputCard;
        int cnt = 0;
        vector<string> pileCards;
        vector<string> handCards;

        while (totalCard--) {
            cin >> inputCard;
            vector<string>* cards;

            if (cnt < 27) {
                cards = &pileCards;
            } else {
                cards = &handCards;
            }
            cards->push_back(inputCard);
            cnt++;
        }

        // printVector(pileCards); printVector(handCards);

        int times = 3;
        int y = 0;

        while (times--) {
            int x = cardValue(pileCards[(int) pileCards.size() - 1]);
            y += x;

            int removes = 10 - x + 1;

            while (removes--) {
                pileCards.pop_back();
            }
        }

        pileCards.insert(pileCards.end(), handCards.begin(), handCards.end());

        cout << "Case " << n << ": " << pileCards[y - 1] << '\n';
    }

    return 0;
}
