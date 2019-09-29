#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

vector<ll> divisor(ll n) { 
  vector<ll> ret;
  for (ll i = 1; (ll)i*i <= n; ++i) { 
    if (n % i == 0) {
      ret.push_back(i);
      if (i*i != n) { ret.push_back(n/i); }
    }
  }
  sort(ret.begin(), ret.end());
  return ret;
};

int main() {
  vector<ll> divs;
  ll n = 36;
  divs = divisor(n);
  cout << "divisors of " << n << " is ..." << endl;
  for (ll d : divs) { 
    cout << d << endl;
  }

  // 最大に近い数の確認
  n = (ll)999983*1000003;
  divs = divisor(n);
  cout << "divisors of " << n << " is ..." << endl;
  for (ll d : divs) { 
    cout << d << endl;
  }
}
