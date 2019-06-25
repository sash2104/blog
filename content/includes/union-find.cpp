#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class UnionFind {
public:
  vector<int> data;
  UnionFind(int size) : data(size, -1) {}

  int find(int x) {
    return data[x] < 0 ? x : data[x] = find(data[x]);
  }

  void unite(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px != py) {
      if (data[py] < data[px]) swap(px, py);
      data[px] += data[py]; data[py] = px;
    }
  }
};

int main() {
  UnionFind uf(5);
  uf.unite(1, 2);
  uf.unite(2, 3);
  uf.unite(3, 4);
  /* 結果は下記のようになる. uf.data[i]が負のものはroot
0 -1
1 -4
2 1
3 1
4 1
   */
  for (int i = 0; i < 5; ++i) {
    cerr << i << " " << uf.data[i] << endl;
  }
}
