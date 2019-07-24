#include <iostream>
#include <vector>

using namespace std;

class Prime {
// n以下の素数を列挙する
public:
  const int n;
  vector<bool> is_prime;
  vector<int> primes;
  Prime(int size) : n(size), is_prime(n, true) {
    for (int i = 2; i <= n; ++i) {
      if (!is_prime[i]) continue;
      primes.push_back(i);
      int tmp = 2*i;
      while (tmp <= n) {
        is_prime[tmp] = false;
        tmp += i;
      }
    }
  }
};

int main() {
  Prime prime(10);
  for (int p : prime.primes) {
    cout << p << endl;
  }
}
