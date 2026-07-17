#pragma once

#include "enumeration.hpp"

/**
 * @brief Binomial Coefficient Prefix Sum Query
 */
template <typename Mint>
struct BinomialPrefixSumQuery {
 private:
  static int check_max_n(int max_n) {
    assert(max_n >= 0);
    return max_n;
  }

  int max_n_, n_ = 0, k_ = -1;
  Mint sum_ = 0, inv_two_;
  Enumeration<Mint> binom_;

 public:
  explicit BinomialPrefixSumQuery(int max_n)
      : max_n_(check_max_n(max_n)),
        inv_two_(Mint(1) / Mint(2)),
        binom_(max_n_) {}

  void reset() {
    n_ = 0;
    k_ = -1;
    sum_ = 0;
  }

  Mint move(int n, int k) {
    assert(0 <= n && n <= max_n_);
    assert(-1 <= k && k <= n);
    while (n_ < n) {
      sum_ += sum_ + binom_.C(n_, k_ + 1);
      ++n_;
      ++k_;
    }
    while (n_ > n) {
      --n_;
      --k_;
      sum_ = (sum_ - binom_.C(n_, k_ + 1)) * inv_two_;
    }
    while (k_ < k) {
      sum_ += binom_.C(n_, k_ + 1);
      ++k_;
    }
    while (k_ > k) {
      --k_;
      sum_ -= binom_.C(n_, k_ + 1);
    }
    return sum_;
  }

  Mint value() const { return sum_; }
};
