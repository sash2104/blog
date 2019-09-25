#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class UnionFind {
public:
  vector<int> data; // sizeとparを同時に管理する
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

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  int size(int x) {
    return -data[find(x)];
  }
};

int main() {
  UnionFind uf(5);
  uf.unite(1, 2);
  uf.unite(2, 3);
  uf.unite(3, 4);

  /* dataとsizeの確認. data[i]が負の点はroot */
  for (int i = 0; i < 5; ++i) {
    cerr << i << " " << uf.data[i] << " " << uf.size(i) << endl;
  }
  /* sameの確認 */
  cerr << "2 and 4 is : " << uf.same(2, 4) << " (1:same, 0:different)" << endl;
  cerr << "0 and 3 is : " << uf.same(0, 3) << " (1:same, 0:different)" << endl;
}
