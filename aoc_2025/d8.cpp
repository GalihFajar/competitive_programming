#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;

template <typename T> using v = vector<T>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define fio(name)                                                              \
  freopen(name ".in", "r", stdin);                                             \
  freopen(name ".out", "w", stdout);
#define psp(x) cout << x << " ";
#define pnl(x) cout << x << "\n";

template <typename T> void print_v(vector<T> &v) {
  for (auto const &elem : v) {
    cout << elem << " ";
  }
  cout << endl;
}

typedef struct Node {
  int x, y, z;

  Node(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
  }
} Node;

using pnn = pair<pair<Node *, int>, pair<Node *, int>>; // {node, idx}
using pnnd = pair<pnn, double>;

double distance(Node *a, Node *b) {
  return (double)sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2) +
                      pow(a->z - b->z, 2));
}

void print_node(Node *n) {
  cout << "{" << n->x << "," << n->y << "," << n->z << "}";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string s;
  v<Node *> nodes;
  while (cin >> s) {
    stringstream ss(s);

    v<string> temp;
    string t;
    while (getline(ss, t, ','))
      temp.push_back(t);

    Node *node = new Node(stoi(temp[0]), stoi(temp[1]), stoi(temp[2]));
    nodes.push_back(node);
  }

  // Constructing pnnd perhaps unnecessary, but good for debugging
  v<pnnd> edges;
  for (int i = 0; i < nodes.size(); i++) {
    Node *a = nodes[i];
    for (int j = i + 1; j < nodes.size(); j++) {
      Node *b = nodes[j];
      edges.push_back({{{a, i}, {b, j}}, distance(a, b)});
    }
  }

  sort(all(edges),
       [](pnnd &a, pnnd &b) -> bool { return a.second < b.second; });

  vi link = vi(nodes.size());
  vi size = vi(nodes.size());

  for (int i = 0; i < nodes.size(); i++)
    link[i] = i;
  for (int i = 0; i < nodes.size(); i++)
    size[i] = 1;

  auto find = [&](int x) {
    while (x != link[x])
      x = link[x];
    return x;
  };

  auto same = [&](int a, int b) { return find(a) == find(b); };

  auto unite = [&](int a, int b) {
    a = find(a);
    b = find(b);
    if (size[a] < size[b])
      swap(a, b);
    size[a] += size[b];
    link[b] = a;
  };

  int count = 0;
  pii latest;
  int first_result = 1;
  for (auto const &e : edges) {
    if (count == 1000) {

      // calculate first answer
      vi size_cp = size;
      sort(all(size_cp));
      reverse(all(size_cp));
      for (int i = 0; i < 3; i++) {
        first_result *= size_cp[i];
      }
    }

    int a = e.first.first.second;
    int b = e.first.second.second;
    if (!same(a, b)) {
      unite(a, b);
      latest = {a, b};
    }

    count++;
  }

  sort(all(size));
  reverse(all(size));

  cout << "#1: " << first_result << endl;
  long long second_result =
      (long long)nodes[latest.first]->x * nodes[latest.second]->x;
  cout << "#2: " << second_result << endl;

  return 0;
}

/*
 *
 *
 */
