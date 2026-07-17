---
title: Binomial Coefficient Prefix Sum
documentation_of: //math/fps/binomial-prefix-sum.hpp
---

多数の二項係数の前綴和を一括で求めます。

# binomial_prefix_sum

```cpp
template <template <typename> class FPS, typename Mint>
vector<Mint> binomial_prefix_sum(const FPS<Mint> &xs, const vector<int> &ms)
```

$Q$ 個の組 $(x_i, m_i)$ に対し、

$$
\sum_{j=0}^{m_i} \binom{x_i}{j}
$$

を順に格納した長さ $Q$ の配列を返します。ただし、体の要素 $x$ に対する二項係数を

$$
\binom{x}{j}=\frac{x(x-1)\dots(x-j+1)}{j!}
$$

と定義します。

## 制約

- `xs.size() == ms.size()`
- $0 \leq m_i \lt$ `Mint::mod()`

## 計算量

$Q=\lvert \mathrm{xs}\rvert$、$M=1+\max_i m_i$ とします。`FormalPowerSeriesFriendlyNTT` を用いた場合、

- 時間計算量: $O((Q+M)\log^2(Q+M))$
- 空間計算量: $O((Q+M)\log(Q+M))$

$Q=0$ の場合は $O(1)$ です。

# 参考

- [组合数前缀和](https://www.cnblogs.com/zkyJuruo/p/16995141.html)
