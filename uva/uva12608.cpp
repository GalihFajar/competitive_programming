#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef vector<pair<long, long>> vpii;


// Lesson learned: try to not make it complicated (e.g. by using redundant things like array & sort)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long tc; cin >> tc;

    while (tc--) {
        long limit, n; cin >> limit >> n;
        long max_in = n;
        long total_distance = 0;
        long current_weight = 0;
        long last_distance_from_dump = 0;
        vpii pickup_points;
        int cnt = 0;

        while (n--) {
            long current_distance_from_dump, weight;
            cin >> current_distance_from_dump >> weight;
            cnt++;

            total_distance += current_distance_from_dump - last_distance_from_dump;
            current_weight += weight;

            if (current_weight > limit) {
                current_weight = weight;
                total_distance += 2 * current_distance_from_dump;

                if (cnt == max_in) {
                    total_distance += current_distance_from_dump;
                    break;
                }

                if (current_weight == limit) {
                    if (cnt == max_in) {
                        total_distance += current_distance_from_dump;
                        break;
                    }

                    current_weight = 0;
                    total_distance += 2 * current_distance_from_dump;
                }
            } else if (current_weight == limit) {
                if (cnt == max_in) {
                    total_distance += current_distance_from_dump;
                    break;
                }

                current_weight = 0;
                total_distance += 2 * current_distance_from_dump;
            }

            if (cnt == max_in) {
                total_distance += current_distance_from_dump;
            }

            last_distance_from_dump = current_distance_from_dump;
        }


        cout << total_distance << '\n';
    }

    return 0;
}
