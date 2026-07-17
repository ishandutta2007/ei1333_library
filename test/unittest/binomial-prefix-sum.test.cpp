// competitive-verifier: STANDALONE

#include "../../template/template.hpp"

#include "../../math/combinatorics/montgomery-mod-int.hpp"
#include "../../math/fps/binomial-prefix-sum.hpp"
#include "../../math/fps/formal-power-series-friendly-ntt.hpp"

using mint = modint998244353;
using Poly = FormalPowerSeriesFriendlyNTT<mint>;

mint naive_binomial_prefix_sum(mint x, int m) {
  mint sum = 0, term = 1;
  for (int i = 0; i <= m; i++) {
    sum += term;
    term *= (x - mint(i)) / mint(i + 1);
  }
  return sum;
}

void check(const Poly& xs, const vector<int>& ms) {
  auto got = binomial_prefix_sum(xs, ms);
  assert(got.size() == xs.size());
  for (int i = 0; i < (int)xs.size(); i++) {
    assert(got[i] == naive_binomial_prefix_sum(xs[i], ms[i]));
  }
}

int main() {
  check({}, {});

  Poly fives(7, mint(5));
  vector<int> prefixes{0, 1, 2, 3, 4, 5, 6};
  assert(binomial_prefix_sum(fives, prefixes) ==
         vector<mint>({1, 6, 16, 26, 31, 32, 32}));
  check(fives, prefixes);

  check(Poly(50, mint(123)), vector<int>(50, 42));
  check(Poly{mint(0), mint(1), mint(-1), mint(1000000000000000000LL),
             mint(1000000000000000000LL)},
        vector<int>{20, 20, 20, 0, 100});

  mt19937_64 rng(123456789);
  for (int rep = 0; rep < 20; rep++) {
    int q = 1 + rng() % 200;
    Poly xs(q);
    vector<int> ms(q);
    for (int i = 0; i < q; i++) {
      int64_t x = (int64_t)(rng() % 2000000000001ULL) - 1000000000000LL;
      xs[i] = mint(x);
      ms[i] = rng() % 300;
    }
    check(xs, ms);
  }
}
