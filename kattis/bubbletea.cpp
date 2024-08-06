#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> bubbleTeas;
    vector<int> toppingPrices;

    int teas;
    int temp;

    cin >> teas;
    temp = teas;
    vector<int> cheapest(teas, INT_MAX);

    while (teas--) {
        int tea;
        cin >> tea;

        bubbleTeas.push_back(tea);
    }

    cin >> teas;

    while (teas--) {
        int topping;

        cin >> topping;
        toppingPrices.push_back(topping);
    }

    teas = temp;
    int cnt = 0;

    while (teas--) {
        int mix;

        cin >> mix;

        while (mix--) {
            int toppingNumber;
            cin >> toppingNumber;

            cheapest[cnt] = min(cheapest[cnt], bubbleTeas[cnt] + toppingPrices[toppingNumber - 1]);
        }

        cnt++;
    }

    int money;
    cin >> money;


    int chpst = INT_MAX;
    for (int p: cheapest) {
        chpst = min(chpst, p);
    }

    int totalTeas = money / chpst;

    printf("%d\n", totalTeas - 1 >= 0 ? totalTeas - 1 : 0);
}
