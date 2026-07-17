---
title: Binomial Coefficient Prefix Sum
documentation_of: //math/fps/binomial-prefix-sum.hpp
---

## 概要

体上の点列 `xs` と非負整数列 `ms` に対し、各 $i$ について

$$
\sum_{j=0}^{\mathrm{ms}_i} \binom{\mathrm{xs}_i}{j}
$$

を返す。

## 使い方

`binomial_prefix_sum(xs, ms)`：各組 `(xs[i], ms[i])` に対する二項係数の前綴和を返す。

`max(ms) < Mint::mod()` を仮定する。`FormalPowerSeriesFriendlyNTT` を用いた場合、$Q=|\mathrm{xs}|$, $M=\max(\mathrm{ms})+1$ として、時間計算量は $O((Q+M)\log^2(Q+M))$、空間計算量は $O((Q+M)\log(Q+M))$ である。

## 参考

- [组合数前缀和](https://www.cnblogs.com/zkyJuruo/p/16995141.html)
