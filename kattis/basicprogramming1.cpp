#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

void handleSeven(vector<int>& A) {
    long long i = 0;
    int ASize = (int) A.size();
    unordered_map<int, bool> visited;

    while (i < ASize && i != ASize - 1) {
        if (visited[i]) {
            cout << "Cyclic\n";
            return;
        }

        visited[i] = true;
        i = A[i];
    }

    if (i >= ASize) {
        cout << "Out\n";
    } else if (i == ASize - 1) {
        cout << "Done\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, A;
    long long sumAll = 0;
    long long sumEven = 0;
    string out = "";
    vector<int> inputs;
    vector<int> temp(3);

    cin >> N >> A;

    while (N--) {
        int input;
        cin >> input;

        inputs.push_back(input);
        sumAll += input;
        sumEven += input % 2 == 0 ? input : 0;
        out += (input % 26) + 'a';
    }

    switch (A) {
        case 1:
            cout << "7\n";
            break;
        case 2:
            if (inputs[0] > inputs[1])
                cout << "Bigger\n";
            else if (inputs[0] == inputs[1])
                cout << "Equal\n";
            else
                cout << "Smaller\n";
            break;
        case 3:
            temp[0] = inputs[0]; temp[1] = inputs[1]; temp[2] = inputs[2];
            sort(temp.begin(), temp.end());
            cout << temp[1] << '\n';
            break;
        case 4:
            cout << sumAll << '\n';
            break;
        case 5:
            cout << sumEven << '\n';
            break;
        case 6:
            cout << out << '\n';
            break;
        case 7:
            handleSeven(inputs);
            break;
    }

    return 0;
}
