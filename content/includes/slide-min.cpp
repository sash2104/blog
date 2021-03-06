#include <iostream>
#include <deque>
#include <vector>

using namespace std;

template <class T>
std::vector<int> slideMin(const std::vector<T>& v, int k) { 
  /* vの連続するk区間の最小値のindexのリストを返す */
  std::vector<int> ret;
  std::deque<int> dq;
  int n = v.size();
  for (int i = 0; i < n; ++i) {
    while (dq.size() && v[dq.back()] >= v[i]) dq.pop_back();
    dq.push_back(i);
    if (i - k + 1 >= 0) {
      ret.push_back(dq.front());
      if (dq.front() <= i-k+1) dq.pop_front();
    }
  }
  return ret;
}

int main() {
  vector<int> v = {1, 3, 5, 4, 2};

  for (int x : v) cout << x << " ";
  cout << endl;

  int k = 3;
  vector<int> ret = slideMin(v, k);
  for (int i = 0; i < ret.size(); ++i) {
    cout << "[" << i << "," << i+k-1 << "] id = " << ret[i] << ", value = " << v[ret[i]] << endl;
  }
}