#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

template <typename T> using v = vector<T>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vp = v<pii>;
using vvp = vector<v<pii>>;
using vb = v<bool>;
using vvb = v<vb>;

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

vp rotate(vp &points) {
  vp rotated_points;

  for (auto const &p : points) {
    rotated_points.push_back({p.second, -p.first});
  }

  return rotated_points;
}

vp flip(vp &points) {
  vp flipped_points;

  for (auto const &p : points) {
    flipped_points.push_back({p.first, -p.second});
  }

  return flipped_points;
}

v<vvp> shapes;

void mark(vvb &field, pii start, vp &shape) {
  for (auto const &x : shape) {
    int i, j;
    i = x.first;
    j = x.second;
    int beg_i, beg_j;
    tie(beg_i, beg_j) = start;

    int new_i = beg_i + i;
    int new_j = beg_j + j;
    bool temp = field[new_i][new_j];
    field[new_i][new_j] = !temp;
  }
}

bool check(vvb &field, pii start, vp &shape) {
  for (auto const x : shape) {
    int i, j;
    i = x.first;
    j = x.second;
    int beg_i, beg_j;
    tie(beg_i, beg_j) = start;
    int new_i = beg_i + i;
    int new_j = beg_j + j;

    if (new_i < 0 || new_j < 0 || new_i >= field.size() ||
        new_j >= field[0].size())
      return false;

    if (field[new_i][new_j])
      return false;
  }

  return true;
}

void normalize(vp &shape) {
  sort(all(shape));

  int offset_r = shape[0].first;
  int offset_c = shape[0].second;

  for (auto &c : shape) {
    c.first -= offset_r;
    c.second -= offset_c;
  }
}

void print_field(vvb &field) {

  for (int i = 0; i < field.size(); i++) {
    for (int j = 0; j < field[i].size(); j++) {
      cout << field[i][j] << " ";
    }
    cout << '\n';
  }
}


bool backtrack(vvb &field, pii start, vi remainings, int remaining_area) {

  bool all_zero = true;
  for (auto const& x: remainings) {
      all_zero &= (x == 0);
  }

  if (all_zero) return true;
  if (remaining_area <= 0) return false;

  int row, col;
  for (int i_ = 0; i_ < field.size(); i_++) {
    for (int j_ = 0; j_ < field[i_].size(); j_++) {
      if (!field[i_][j_]) {
        row = i_;
        col = j_;
        for (int i = 0; i < shapes.size(); i++) {
          if (remainings[i] > 0) {
            for (int j = 0; j < shapes[i].size(); j++) {
              if (!check(field, {row, col}, shapes[i][j])) {
                continue;
              }
              mark(field, {row, col}, shapes[i][j]);
              remainings[i]--;
	      int rem_area_temp = remaining_area;
	      remaining_area = remaining_area - (int) shapes[i][j].size();
              if (backtrack(field, {row, col}, remainings, remaining_area))
                return true;
              remainings[i]++;
              mark(field, {row, col}, shapes[i][j]);
	      remaining_area = rem_area_temp;
            }
          }
        }
      }
    }
  }

  return false;
}

int count_necessary_area(vi remainings) {
    int area = 0;
    for (int i = 0; i < remainings.size(); i++) {
	area += remainings[i] * shapes[i][0].size();
    }

    return area;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // fio("<filename_prefix>")
  string temp;

  v<string> shape;
  v<v<string>> shapes_str;
  v<string> rem_inputs;

  while (getline(cin, temp)) {
    if (temp.size() >= 4) {
      rem_inputs.push_back(temp);
    }

    if (temp.size() == 2)
      continue;
    if (temp.empty()) {
      if (!shape.empty())
        shapes_str.push_back(shape);
      shape.clear();
    }

    shape.push_back(temp);
  }

  for (auto const &s : shapes_str) {
    v<pii> points;
    for (int i = 0; i < s.size(); i++) {
      for (int j = 0; j < s[i].size(); j++) {
        if (s[i][j] == '#')
          points.push_back({i, j});
      }
    }
    shapes.push_back({points});
  }

  for (int i = 0; i < shapes.size(); i++) {
    vp shape_1 = rotate(shapes[i][0]);
    shapes[i].push_back(shape_1);
    shapes[i].push_back(flip(shape_1));

    vp shape_2 = rotate(shape_1);
    shapes[i].push_back(shape_2);
    shapes[i].push_back(flip(shape_2));

    vp shape_3 = rotate(shape_2);
    shapes[i].push_back(shape_3);
    shapes[i].push_back(flip(shape_3));

    shapes[i].push_back(flip(shapes[i][0]));
  }

  for (auto &s : shapes) {
    for (auto &s_ : s) {
      normalize(s_);
    }
  }

  int ans = 0;
  for (auto const &s : rem_inputs) {
    string temp = "";
    pii field_size;
    vi remainings;
    for (auto const &c : s) {
      if (c == 'x') {
        field_size.first = stoi(temp);
        temp.clear();
      } else if (c == ':') {
        field_size.second = stoi(temp);
        temp.clear();
      } else if (c == ' ') {
        if (!temp.empty()) {
          remainings.push_back(stoi(temp));
        }

        temp.clear();
      } else {
        temp += c;
      }
    }

    if (!temp.empty())
      remainings.push_back(stoi(temp));
    vvb field = vvb(field_size.second, vb(field_size.first, false));
    int field_area = field_size.first * field_size.second;

    // NOTE: This should be a proper way to solve, but it turns out to be a trick question
    // ans += backtrack(field, {0, 0}, remainings, field_size.second * field_size.first;
    if (count_necessary_area(remainings) <= field_area) {
	ans += 1;
    }     
  }

  cout << "Answer: " << ans << endl;

  return 0;
}

/*
 *
 *
 */
