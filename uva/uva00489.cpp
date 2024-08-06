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

    int tc;
    int count = 0;
    while (1) {
        cin >> tc;
        if (tc == -1) return 0;

        string word, guess;
        cin >> word >> guess;

        unordered_map<char, int> word_map;
        int remaining_word_cnt = word.size();

        for (int i = 0; i < (int) word.size(); i++) {
            word_map[word[i]]++;
        }

        int game_counter = 7;
        for (int i = 0; i < (int) guess.size() && game_counter > 0 && remaining_word_cnt > 0; i++) {
            if (word_map.count(guess[i])) {
                remaining_word_cnt -= word_map[guess[i]];
                word_map[guess[i]] = 0;
            }
            else
                game_counter--;
        }


        cout << "Round " << tc << '\n';
        if (game_counter <= 0 && remaining_word_cnt > 0) {
            cout << "You lose.\n";
        } else if (remaining_word_cnt == 0 && game_counter >= 0) {
            cout << "You win.\n";
        } else {
            cout << "You chickened out.\n";
        }
    }

    return 0;
}
