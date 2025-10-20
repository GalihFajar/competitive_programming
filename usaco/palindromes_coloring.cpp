#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

template <typename T> using v = vector<T>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fio("<filename_prefix>")
    int tc; cin >> tc;
    while (tc--) {
	int n, k;
	cin >> n >> k;
	string s; cin >> s;

	vi freq(26, 0);

	for (char& c: s) {
	    freq[c - 'a']++;
	}

	int num_pairs = 0;
	int num_odds = 0;

	for (int i = 0; i < 26; i++) {
	    num_pairs += freq[i] / 2;
	    num_odds += (freq[i] % 2 == 1);
	}

	int res = 2 * (num_pairs / k); // if num of pairs > k then all is guaranteed to have length of num_pairs * 2
	num_odds += 2 * (num_pairs % k); // if there are remainders, split the characters, ultimately to distribute

	res += (num_odds >= k);
	cout << res << endl;
    }

    

    return 0;
}


/*
 * palindrome of 1 character is guaranteed
 * if palindrome length is odd, then there should be strictly 1 character that count = odd, and the others are strictly evens
 * if palindrome length is even, then all the characters should be even
 *
 *
 * Sample case:
 * bxyaxzay
 * a = 2
 * b = 1
 * x = 2
 * y = 2
 * z = 1
 *
 * total length = 6
 * divided by two colors (k = 2) = 3 (no remainders)
 * each can have 3 chars
 *
 * one of the biggest constraint is that not all chars must be colored
 * but one nice constraint is that the palindrome result must be optimal (as long as possible)
 * means that one of the color CANNOT devour all of the chars if it's actually divisable
 *
 * Sample case:
 * abcdef
 * a,b,c,d,e,f = 1
 * k = 1
 *
 * sample case:
 * eatoohd
 * o = 2
 * a,t,h,d,e = 1
 * k = 2
 * 
 * Sample case:
 * abcabcabcac
 * a = 4
 * b = 3
 * c = 4
 *
 * k -> 2
 *
 * sample case:
 * abcdef
 * a = 1
 * b = 1
 * c = 1
 * d = 1
 * e = 1
 * f = 1
 *
 * k -> 2
 *
 * answer = 1
 *
 * let' try greedy: output the minimum from char count
 * wait even with counting, it would take 10^5 * 10^4 time complexity, definitely TLE
 *
 *
 * Ok let's see hints
 * Knew it it involvees maths!
 * Other note is that, it guarantees the total n wouldn't exceed 10^5, so in other words the constraint is actualyy 10^5
*/
