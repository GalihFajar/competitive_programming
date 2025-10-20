#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef vector<string> vs;

void rot_90_deg(vs& mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = i; j < mat[i].size(); j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }

    for (int i = 0; i < mat.size(); i++) {
        int l = 0, r = mat[i].size() - 1; 
        while (l < r) {
            swap(mat[i][l], mat[i][r]);
            l++; r--;
        }
    }
}

void reflect(vs& mat) {
    for (int j = 0; j < mat[0].size(); j++) {
        int l = 0, r = mat.size() - 1;
        while (l < r) {
            swap(mat[l][j], mat[r][j]);
            l++; r--;
        }
    }
}

bool compare(vs& mat1, vs& mat2) {
    if (mat1.size() != mat2.size()) return false;
    for (int i = 0; i < mat1.size(); i++) {
        if (mat1[i] != mat2[i]) return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc = 0;

    int n; 
    while (cin >> n) {
        cin.ignore(1000, '\n');
        vs ori_mat, test_mat;
        while (n--) {
            string a, b; cin >> a >> b;
            ori_mat.push_back(a); 
            test_mat.push_back(b);
        }

        cout << "Pattern " << ++tc << " was ";

        if (compare(ori_mat, test_mat)) {
            cout << "preserved.\n";
            continue;
        }

        vs cp_mat = ori_mat;

        reflect(cp_mat);
        if (compare(cp_mat, test_mat)) {
            cout << "reflected vertically.\n";
            continue;
        } else {
            rot_90_deg(cp_mat);
            if (compare(cp_mat, test_mat)) {
                cout << "reflected vertically and rotated 90 degrees.\n";
                continue;
            }

            rot_90_deg(cp_mat);
            if (compare(cp_mat, test_mat)) {
                cout << "reflected vertically and rotated 180 degrees.\n";
                continue;
            }

            rot_90_deg(cp_mat);
            if (compare(cp_mat, test_mat)) {
                cout << "reflected vertically and rotated 270 degrees.\n";
                continue;
            }
        }

        cp_mat = ori_mat;

        rot_90_deg(cp_mat);
        if (compare(cp_mat, test_mat)) {
            cout << "rotated 90 degrees.\n";
            continue;
        }

        rot_90_deg(cp_mat);
        if (compare(cp_mat, test_mat)) {
            cout << "rotated 180 degrees.\n";
            continue;
        }

        rot_90_deg(cp_mat);
        if (compare(cp_mat, test_mat)) {
            cout << "rotated 270 degrees.\n";
            continue;
        }

        cout << "improperly transformed.\n";
    }

    return 0;
}
