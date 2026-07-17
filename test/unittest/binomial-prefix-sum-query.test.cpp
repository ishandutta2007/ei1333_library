// competitive-verifier: STANDALONE

#include "../../template/template.hpp"

#include "../../math/combinatorics/binomial-prefix-sum-query.hpp"
#include "../../math/combinatorics/binomial-table.hpp"
#include "../../math/combinatorics/montgomery-mod-int.hpp"

using mint = modint998244353;

int main() {
  constexpr int N = 50;
  auto binom = binomial_table<mint>(N);
  vector<vector<mint> > prefix(N + 1, vector<mint>(N + 2));
  for (int n = 0; n <= N; n++) {
    for (int k = 0; k <= n; k++) {
      prefix[n][k + 1] = prefix[n][k] + binom[n][k];
    }
  }

  BinomialPrefixSumQuery<mint> query(N);
  assert(query.value() == mint(0));
  for (int n = 0; n <= N; n++) {
    for (int k = -1; k <= n; k++) {
      assert(query.move(n, k) == prefix[n][k + 1]);
      assert(query.value() == prefix[n][k + 1]);
    }
  }
  for (int n = N; n >= 0; n--) {
    for (int k = n; k >= -1; k--) {
      assert(query.move(n, k) == prefix[n][k + 1]);
    }
  }

  mt19937 rng(123456789);
  for (int rep = 0; rep < 1000; rep++) {
    int n = rng() % (N + 1);
    int k = (int)(rng() % (n + 2)) - 1;
    assert(query.move(n, k) == prefix[n][k + 1]);
  }

  query.reset();
  assert(query.value() == mint(0));
  assert(query.move(N, N) == mint(2).pow(N));

  int k = N / 2;
  assert(query.move(N, k) == prefix[N][k + 1]);
  for (int n = N - 1; n >= 0; n--) {
    if ((n & 1) && k > 0) --k;
    k = min(k, n);
    assert(query.move(n, k) == prefix[n][k + 1]);
  }
}
