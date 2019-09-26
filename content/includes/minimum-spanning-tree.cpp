#include <algorithm>
#include <iostream>
#include <tuple>
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

struct Edge {
  int cost, from, to;
  Edge() {}
  Edge(int c, int f, int t) : cost(c), from(f), to(t) {}
  friend bool operator < (const Edge& lhs, const Edge& rhs) { return lhs.cost < rhs.cost; };
  friend bool operator > (const Edge& lhs, const Edge& rhs) { return rhs < lhs; };
  friend bool operator <= (const Edge& lhs, const Edge& rhs) { return !(lhs > rhs); };
  friend bool operator >= (const Edge& lhs, const Edge& rhs) { return !(lhs < rhs); };
};

struct MinimumSpanningTree {
  struct UnionFind uf;
  uint64_t weight; // 最小全域木の辺の重みの和
  MinimumSpanningTree(int V, vector<Edge> &edges) : uf(V), weight(0) {
    sort(edges.begin(), edges.end());
    for (auto e : edges) { 
      if (uf.same(e.from, e.to)) continue;
      uf.unite(e.from, e.to);
      weight += e.cost;
    }
  }
};

int main() {
  vector<Edge> edges;
  int V, E;
  cin >> V >> E;
  for (int i = 0; i < E; ++i) {
    int x, y, w;
    cin >> x >> y >> w;
    edges.emplace_back(w, x, y);
  }
  MinimumSpanningTree mst(V, edges);
  cout << mst.weight << endl;
}