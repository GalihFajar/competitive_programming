#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <set>
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

stack<int> stk; 
queue<int> que;
deque<int> deq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fio("<filename_prefix>")
    int n; cin >> n;

    vi nums;
    for (int i_ = 0; i_ < n; i_++) {
	int x; cin >> x;

	if (x == 0) {
	    vi nums_clone = nums;
	    sort(all(nums_clone), greater<int>());
	    bool stack_used = false;
	    bool queue_used = false;
	    bool deque_used = false;
	    v<string> ops;
	    multiset<int> best;
	    int cnt = 0;
	    
	    for (int i = 0; i < 3 && i < nums_clone.size(); i++) {
		best.insert(nums_clone[i]);
	    }

	    for (int i = 0;  i < nums.size(); i++) {
		if (best.find(nums[i]) == best.end()) {
		    cout << "pushBack\n";
		    continue;
		}
		best.erase(best.find(nums[i]));

		if (!stack_used) {
		    stack_used = true;
		    cout << "pushStack\n";
		    ops.push_back("popStack");
		} else if (!queue_used) {
		    queue_used = true;
		    cout << "pushQueue\n";
		    ops.push_back("popQueue");
		} else if (!deque_used){
		    deque_used = true;
		    cout << "pushFront\n";
		    ops.push_back("popFront");
		}
		cnt++;
	    }

	    cout << cnt; if (cnt != 0) cout << " ";
	    for (int i = 0; i < (int) ops.size(); i++) {
		cout << ops[i];
		if (i != (int) ops.size() - 1)
		    cout << " ";
	    }
	    cout << endl;

	    nums.clear();
	    best.clear();
	} else {
	    nums.push_back(x);
	}

    }
    for (int i = 0; i < nums.size(); i++) { std::cout << "pushBack\n"; }
    

    return 0;
}


/*
 *
 *
*/
