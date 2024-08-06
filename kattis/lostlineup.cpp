#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    vector<pair<int, int>> v;
    scanf("%d", &n);
    n--;
    int cnt = 2;

    while (n--) {
        int in;
        scanf("%d", &in);
        v.push_back({in, cnt++});
    }

    sort(v.begin(), v.end());

    printf("1 ");
    for (int i = 0; i < (int) v.size(); i++) {
        if (i < v.size() - 1) {
            printf("%d ", v[i].second);
        } else {
            printf("%d\n", v[i].second);
        }
    }

    return 0;
}
