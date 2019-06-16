#include <iostream>
#include <map>
#include <vector>
using namespace std;

// pair
template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p) {return s << "(" << p.first << ", " << p.second << ")";}
// vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << "\t";
  }
  return s;
}
// 2 dimentional vector
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) {
    s << vv[i] << endl;
  }
  return s;
}
// map
template<typename T1, typename T2> ostream& operator<<(ostream& s, const map<T1, T2>& m) {
  s << "{" << endl;
  for (typeof(m.begin()) itr = m.begin(); itr != m.end(); ++itr) {
    s << "\t" << (*itr).first << " : " << (*itr).second << endl;
  }
  s << "}" << endl;
  return s;
}

#if 0
void sample_pair() {
  pair<int, int> p = make_pair(1, 2);
  cout << p << endl;
}

void sample_vector() {
  int N = 10;
  vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    a[i] = i;
  }
  cout << "===== vector<int> =====" << endl;
  cout << a << endl;

  vector< vector<int> > b(N, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      b[i][j] = i * j;
    }
  }
  cout << endl << "===== vector< vector<int> > =====" << endl;
  cout << b << endl;
}

void sample_map() {
  map<int, char> m;
  for (int i = 0; i < 26; ++i) {
    m[i] = 'a' + i;
  }
  cout << m << endl;
}

int main() {
  sample_pair();
  sample_vector();
  sample_map();
}
#endif
