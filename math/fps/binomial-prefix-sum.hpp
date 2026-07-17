#pragma once

#include "multipoint-evaluation.hpp"

/**
 * @brief Binomial Coefficient Prefix Sum
 */
template <template <typename> class FPS, typename Mint>
vector<Mint> binomial_prefix_sum(const FPS<Mint>& xs, const vector<int>& ms) {
  assert(xs.size() == ms.size());
  const int q = (int)xs.size();
  if (q == 0) return {};

  int max_m = -1;
  for (auto& m : ms) {
    assert(m >= 0);
    max_m = max(max_m, m);
  }

  int size = 1;
  while (size < max_m + 2) size <<= 1;

  // (sum, term) -> (sum + term * b, term * a) is the transition
  // over an interval of binomial coefficients.
  vector<FPS<Mint> > a(2 * size), b(2 * size);
  for (int i = 0; i < size; i++) {
    if (i <= max_m) {
      assert(Mint(i + 1) != Mint(0));
      Mint inv = Mint(1) / Mint(i + 1);
      a[size + i] = {-Mint(i) * inv, inv};
      b[size + i] = {Mint(1)};
    } else {
      a[size + i] = {Mint(1)};
      b[size + i] = {Mint(0)};
    }
  }
  for (int i = size; --i > 0;) {
    a[i] = a[i << 1] * a[i << 1 | 1];
    b[i] = b[i << 1] + a[i << 1] * b[i << 1 | 1];
  }

  vector<vector<int> > ids(size);
  for (int i = 0; i < q; i++) ids[ms[i] + 1].push_back(i);

  vector<int> count(2 * size);
  vector<FPS<Mint> > product(2 * size, FPS<Mint>{Mint(1)});
  for (int i = 0; i < size; i++) {
    count[size + i] = (int)ids[i].size();
    if (ids[i].empty()) continue;
    FPS<Mint> points;
    points.reserve(ids[i].size());
    for (auto& id : ids[i]) points.push_back(xs[id]);
    product[size + i] = subproduct_tree(points)[1];
  }
  for (int i = size; --i > 0;) {
    count[i] = count[i << 1] + count[i << 1 | 1];
    product[i] = product[i << 1] * product[i << 1 | 1];
  }

  vector<Mint> ans(q);
  // Reductions to the same child share the inverse of the reversed modulus.
  auto inverse_size = [](const FPS<Mint>& f, const FPS<Mint>& mod) {
    return max(0, (int)f.size() - (int)mod.size() + 1);
  };
  auto remainder = [&](FPS<Mint> f, const FPS<Mint>& mod,
                       const FPS<Mint>& rev_inv) {
    if (f.size() < mod.size()) return f;
    int n = (int)f.size() - (int)mod.size() + 1;
    auto quotient = (f.rev().pre(n) * rev_inv.pre(n)).pre(n).rev(n);
    f -= quotient * mod;
    f.resize(mod.size() - 1);
    f.shrink();
    return f;
  };
  auto dfs = [&](auto& self, int k, int l, int r, FPS<Mint> sum,
                 FPS<Mint> term) -> void {
    if (r - l == 1) {
      FPS<Mint> points;
      points.reserve(ids[l].size());
      for (auto& id : ids[l]) points.push_back(xs[id]);
      auto values = multipoint_evaluation(sum, points);
      for (int i = 0; i < (int)ids[l].size(); i++) {
        ans[ids[l][i]] = values[i];
      }
      return;
    }

    int mid = (l + r) >> 1;
    if (count[k << 1]) {
      auto& mod = product[k << 1];
      int n = max(inverse_size(sum, mod), inverse_size(term, mod));
      FPS<Mint> rev_inv;
      if (n) rev_inv = mod.rev().inv(n);
      self(self, k << 1, l, mid, remainder(sum, mod, rev_inv),
           remainder(term, mod, rev_inv));
    }
    if (count[k << 1 | 1]) {
      auto& mod = product[k << 1 | 1];
      int n = (int)mod.size() - 2;
      n = max(n, inverse_size(sum, mod));
      n = max(n, inverse_size(term, mod));
      n = max(n, inverse_size(a[k << 1], mod));
      n = max(n, inverse_size(b[k << 1], mod));
      FPS<Mint> rev_inv;
      if (n) rev_inv = mod.rev().inv(n);

      auto reduced_sum = remainder(sum, mod, rev_inv);
      auto reduced_term = remainder(term, mod, rev_inv);
      auto reduced_a = remainder(a[k << 1], mod, rev_inv);
      auto reduced_b = remainder(b[k << 1], mod, rev_inv);
      auto next_sum =
          reduced_sum + remainder(reduced_term * reduced_b, mod, rev_inv);
      auto next_term = remainder(reduced_term * reduced_a, mod, rev_inv);
      self(self, k << 1 | 1, mid, r, next_sum, next_term);
    }
  };
  dfs(dfs, 1, 0, size, FPS<Mint>{Mint(0)}, FPS<Mint>{Mint(1)});
  return ans;
}
