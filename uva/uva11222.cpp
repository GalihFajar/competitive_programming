// suboptimal solution, using hashmap would be better

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void print_vec(vi& v) {
    if (v.empty()) {
        cout << "\n"; return;
    }
    for (int i = 0; i < v.size(); i++) {
        if (i == v.size() - 1) {
            cout << v[i] << '\n';
        } else {
            cout << v[i] << " ";
        }
    }
}

void print_ans(pair<char, vi*>& v) {
    cout << v.first << " "; 
    if (!v.second->empty()) cout << (int) v.second->size() << " ";
    else cout << (int) v.second->size();
    print_vec(*v.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    int tc_ = 0;
    while (tc--) {
        cout << "Case #" << ++tc_ << ":\n";
        vi a, b, c;
        vi* v_ptr = NULL;
        for (int t_ = 0; t_ < 3; t_++) {
            int n; cin >> n;
            if (t_ == 0) v_ptr = &a;
            else if (t_ == 1) v_ptr = &b;
            else if (t_ == 2) v_ptr = &c;
            while (n--) {
                int in; cin >> in;
                v_ptr->push_back(in);
            }
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());

        vi a_ans, b_ans, c_ans;
        for (int x: a) {
            bool unique = true;

            for (int y: b) {
                if (x == y) unique = unique && false;
            }

            for (int z: c) {
                if (x == z) unique = unique && false;
            }

            if (unique) a_ans.push_back(x);
        }

        // check b
        for (int x: b) {
            bool unique = true;

            for (int y: a) {
                if (x == y) unique = unique && false;
            }

            for (int z: c) {
                if (x == z) unique = unique && false;
            }

            if (unique) b_ans.push_back(x);
        }

        // check c
        for (int x: c) {
            bool unique = true;

            for (int y: a) {
                if (x == y) unique = unique && false;
            }

            for (int z: b) {
                if (x == z) unique = unique && false;
            }

            if (unique) c_ans.push_back(x);
        }


        pair<char, vi*> ap = {'1', &a_ans}, bp = {'2', &b_ans}, cp = {'3', &c_ans};
        vector<pair<char, vi*>> asdf = {ap, bp, cp};
        sort(asdf.begin(), asdf.end(), [](pair<char, vi*> a, pair<char, vi*> b) -> bool {
                return a.second->size() > b.second->size();
            }
        );

        vector<pair<char, vi*>*> ans;

        int max_len = asdf[0].second->size();
        ans.push_back(&asdf[0]);
        for (int i = 1; i < 3; i++) {
            if ((int) asdf[i].second->size() == max_len) {
                ans.push_back(&asdf[i]);
            }
        }

        sort(ans.begin(), ans.end(), [](pair<char, vi*>* a, pair<char, vi*>* b) -> bool {
                return a->first < b->first;
            }
        );

        for (auto x: ans) {
            print_ans(*x);
        }
    }

    return 0;
}
