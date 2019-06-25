#include <iostream>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;
ll fact[100010];
 
// a^b % MOD を計算して返す
ll power(ll a, ll b) {
  if (b == 0) {
    return 1;
  } else {
    ll ans = power(a, b / 2); ans = ans * ans; ans = ans % MOD;
    if (b % 2 == 1) ans = ans * a;
    ans = ans % MOD;
    return ans;
  }
}
 
 // nCr % MOD を計算して返す
ll choose(ll n, ll r) {
  ll ans = fact[n];
  ans = fact[n] * power(fact[r], MOD-2); ans = ans % MOD;
  ans = ans * power((fact[n-r] + MOD) % MOD, MOD-2); ans = ans % MOD;
  return ans;
}

int main() {
  int n = 100000;
  fact[0] = 1;
  for (int i = 0; i < n; ++i) {
    fact[i+1] = fact[i]*(i+1)%MOD;
  }
  // 6C3 % (1e9+7) = 20
  cout << "6C3: " << choose(6, 3) << endl;
  // 666C390 % (1e9+7) = 9951876
  cout << "666C390: " << choose(666, 390) << endl;
}